#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <getopt.h>

#include "cachelab.h"

// S：缓存组数，s：缓存组索引位数，E：缓存行数，b：块偏移位数
int S, s, E, b;

// 是否输出调试信息
int verbose = 0;

// hits：缓存命中次数，misses：缓存不命中次数，evictions：缓存驱逐次数
int hits = 0, misses = 0, evictions = 0;

// trace文件名
char tracefile[50];

typedef struct {
    int valid_bit; //有效位
    int tag; // 标记位
    int timestamp; //LRU时间戳
} cache_line, *cache_group, **cache;

cache cache_simulator = NULL;

void print_usage()
{
    puts("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>");
    puts("Options:");
    puts("   -h\t\tPrint this help message.");
    puts("   -v\t\tOptional verbose flag.");
    puts("   -s <num>\tNumber of set bits (S = 2^s is the number of sets).");
    puts("   -E <num>\tNumber of lines per set.");
    puts("   -b <num>\tNumber of block bits (B = 2^b is the block size).");
    puts("   -t <file>\tTrace file.");
    putchar('\n');
    puts("Exampes:");
    puts("   linux> ./csim -s 4 -E 1 -b 4 -t traces/yi.trace");
    puts("   linux> ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace");
    exit(0);
}

void parse_arg(int argc, char *argv[])
{
    int val;
    while ((val = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (val) {
        case 'h':
            print_usage();
            break;
        case 'v':
            verbose = 1;
            break;
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            strcpy(tracefile, optarg);
            break;
        default:
            print_usage();
            break;
        }    
    }

    // 如果参数不合法
    if (s <= 0 || E <= 0 || b <=0) {
        printf("parameter value error\n");
        exit(-1);
    }

    // S = 2^s
    S = 1 << s;
}

/*
 * 初始化缓存
 */
void init_cache(int S, int E)
{
    cache_simulator = (cache) malloc(sizeof(cache_group) * S);
    for (int i = 0; i < S; i++) {
        cache_simulator[i] = (cache_group) malloc(sizeof(cache_line) * E);
        for (int j = 0; j <  E; j++) {
            cache_simulator[i][j].valid_bit = 0;
            cache_simulator[i][j].tag = 0;
            cache_simulator[i][j].timestamp = 0;
        }
    }
}

/**
 * 更新缓存，operator、size以及call_count只用于调试
 * call_count表示对于trace文件的当前行来说，第call_count次调用该方法，用于调试operator='M'
 */
void update_cache(char operator, unsigned int address, int size, int call_count)
{
    int mask = ~(~0 << s);
    int set_idx = (address >> b) & mask;
    int tag = address >> (s + b);
    int max_timestamp = INT_MIN;
    int max_timestamp_idx = -1;

    // 如果命中
    for (int i = 0; i < E; i++) {
        if (cache_simulator[set_idx][i].valid_bit && cache_simulator[set_idx][i].tag == tag) {        
            hits++;
            cache_simulator[set_idx][i].timestamp = 0;

            // 打印调试信息
            if (verbose) {
                if (operator == 'M' && call_count > 1) {
                    printf(" hit\n");
                } else {
                    printf("%c %x,%d hit", operator, address, size);
                    if (operator != 'M') {
                        putchar('\n');
                    }
                }
            }
            return ;
        }
    }

    // 没有命中
    misses++;
    if (verbose) {
        printf("%c %x,%d miss", operator, address, size); 
        if (operator != 'M') {
            putchar('\n');
        } 
    }

    // 如果存在空行
    for (int i = 0; i < E; i++) {
        if (!cache_simulator[set_idx][i].valid_bit) {
            cache_simulator[set_idx][i].valid_bit = 1;
            cache_simulator[set_idx][i].tag = tag;
            cache_simulator[set_idx][i].timestamp = 0;
            return ;
        }
    }

    // 没有空行，则执行替换策略：LRU（Least Recently Used）
    evictions++;
    for (int i = 0; i < E; i++) {
        if (cache_simulator[set_idx][i].timestamp > max_timestamp) {
            max_timestamp = cache_simulator[set_idx][i].timestamp;
            max_timestamp_idx = i;
        }
    }
    cache_simulator[set_idx][max_timestamp_idx].tag = tag;
    cache_simulator[set_idx][max_timestamp_idx].timestamp = 0;
}

/**
 * 更新LRU时间戳
 */
void update_timestamp()
{
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < E; j++) {
            if (cache_simulator[i][j].valid_bit) {
                cache_simulator[i][j].timestamp++;
            }
        }
    }
}

/**
 * 释放缓存
 */
void free_cache()
{
    for (int i = 0; i < S; i++) {
        free(cache_simulator[i]);
    }
    free(cache_simulator);
}

/**
 * 解析缓存文件
 */
void parse_trace(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("file open error\n");
        exit(-1);
    }

    char operator;
    unsigned int address;
    int size;
    while (fscanf(fp, " %c %x,%d", &operator, &address, &size) != EOF) {
        switch (operator) {
        case 'I': // 不处理
            break;
        case 'L':
            update_cache(operator, address, size, 1);
            break;
        case 'S':
            update_cache(operator, address, size, 1);
            break;
        case 'M':
            // 先加载数据，再存储数据
            update_cache(operator, address, size, 1);
            update_cache(operator, address, size, 2);
            break;
        }
        update_timestamp();
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    // 1.解析命令行参数
    parse_arg(argc, argv);

    // 2.初始化缓存
    init_cache(S, E);

    // 3.解析trace文件
    parse_trace(tracefile);

    // 4.释放缓存
    free_cache();

    // 5.输出统计信息
    printSummary(hits, misses, evictions);
    return 0;
}
