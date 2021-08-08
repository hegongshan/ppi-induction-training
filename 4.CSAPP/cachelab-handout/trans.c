/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);


void transpose_32x32(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, k;
    int x0, x1, x2, x3, x4, x5, x6, x7;

    for (i = 0; i < M; i += 8) {
        for (j = 0; j < N; j += 8) {
            for (k = i; k < i + 8; k++) {          
                x0 = A[k][j];
                x1 = A[k][j + 1];
                x2 = A[k][j + 2];
                x3 = A[k][j + 3];
                x4 = A[k][j + 4];
                x5 = A[k][j + 5];
                x6 = A[k][j + 6];
                x7 = A[k][j + 7];

                B[j][k] = x0;
                B[j + 1][k] = x1;
                B[j + 2][k] = x2;
                B[j + 3][k] = x3;
                B[j + 4][k] = x4;
                B[j + 5][k] = x5;
                B[j + 6][k] = x6;
                B[j + 7][k] = x7;
            }
        }
    }
}

void transpose_64x64(int M, int N, int A[N][M], int B[N][M])
{
    int i, j, k;
    int x0, x1, x2, x3, x4, x5, x6, x7;

    for (i = 0; i < N; i += 8) {
        for (j = 0; j < M; j += 8) {
            for (k = i; k < i + 4; k++) {
                x0 = A[k][j]; 
                x1 = A[k][j + 1];
                x2 = A[k][j + 2];
                x3 = A[k][j + 3];
                x4 = A[k][j + 4];
                x5 = A[k][j + 5];
                x6 = A[k][j + 6];
                x7 = A[k][j + 7];

                B[j][k] = x0;
                B[j + 1][k] = x1;
                B[j + 2][k] = x2;
                B[j + 3][k] = x3;

                B[j][k + 4] = x4;
                B[j + 1][k + 4] = x5;
                B[j + 2][k + 4] = x6;
                B[j + 3][k + 4] = x7;
            }
            for (k = j; k < j + 4; k++) {
                x4 = B[k][i + 4];
                x5 = B[k][i + 5];
                x6 = B[k][i + 6];
                x7 = B[k][i + 7];

                x0 = A[i + 4][k];
                x1 = A[i + 5][k];
                x2 = A[i + 6][k];
                x3 = A[i + 7][k];
                B[k][i + 4] = x0;
                B[k][i + 5] = x1;
                B[k][i + 6] = x2;
                B[k][i + 7] = x3;

                B[k + 4][i] = x4;
                B[k + 4][i + 1] = x5;
                B[k + 4][i + 2] = x6;
                B[k + 4][i + 3] = x7;
            }
            for (k = i + 4; k < i + 8; k++) {
                x4 = A[k][j + 4];
                x5 = A[k][j + 5];
                x6 = A[k][j + 6];
                x7 = A[k][j + 7];

                B[j + 4][k] = x4;
                B[j + 5][k] = x5;
                B[j + 6][k] = x6;
                B[j + 7][k] = x7;
            }
        }
    }
}

void transpose_61x67(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;
    int x0, x1, x2, x3, x4, x5, x6, x7;
    int n = N / 8 * 8;
    int m = M / 8 * 8;

    // [0...n][0...m]
    for (j = 0; j < m; j += 8) {  
        for (i = 0; i < n; i++) {
            x0 = A[i][j];
            x1 = A[i][j + 1];
            x2 = A[i][j + 2];
            x3 = A[i][j + 3];
            x4 = A[i][j + 4];
            x5 = A[i][j + 5];
            x6 = A[i][j + 6];
            x7 = A[i][j + 7];

            B[j][i] = x0;
            B[j + 1][i] = x1;
            B[j + 2][i] = x2;
            B[j + 3][i] = x3;
            B[j + 4][i] = x4;
            B[j + 5][i] = x5;
            B[j + 6][i] = x6;
            B[j + 7][i] = x7;
        }
    }

    // [0...n-1][m..M]
    for (i = 0; i < n; i++) {
        for (j = m; j < M; j++) {
            B[j][i] = A[i][j];
        }
    }

    // [n...N][0...m-1]
    for (i = n; i < N; i++) {
        for (j = 0; j < m; j++) {
            B[j][i] = A[i][j];
        }
    }

    // [n...N][m...M]
    for (i = n; i < N; i++) {
        for (j = m; j < M; j++) {
            B[j][i] = A[i][j];
        }
    }
}

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if (M == 32 && N == 32) {
        transpose_32x32(M, N, A, B);
    } else if (M == 64 && N == 64) {
        transpose_64x64(M, N, A, B);
    } else  {
        transpose_61x67(M, N, A, B);
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

