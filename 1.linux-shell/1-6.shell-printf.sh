#!/bin/bash

echo "----Shell printf----"

# echo 默认换行，printf默认不换行
echo "--echo vs. printf--"
echo "echo：Hello, shell!"
printf "printf：Hello, shell!\n"

printf "\n--Test printf--\n"
printf "%-15s %-8s %4s\n" 姓名 性别 体重kg  
printf "%-15s %-8s %4.2f\n" 郭靖 男 66.1234
printf "%-15s %-8s %4.2f\n" 小龙女 女 42.6543
printf "%-15s %-8s %4.2f\n" 杨康 男 58.9876

# 双引号
printf "%d %s\n" 1 "abc"
# 单引号
printf '%d %s\n' 1 "abc"
# 不用引号
printf %s "abcdefghi"
printf %s "abc" "def" "ghi"

printf "%s\n" "abc" "def" "ghi"
printf "%s %s %s\n" a b c d e f g h i

# 测试不添加参数
printf "%s and %d \n"

# 测试%b
printf "A string without processing: %s\n" "a\nb"
printf "A string with processing: %b\n" "a\nb"

# 测试\a
printf "www.hegongshan.com \a"