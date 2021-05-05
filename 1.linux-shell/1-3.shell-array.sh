#!/bin/bash

# Shell 数组
echo "----Shell 数组----"
schools=("ccnu" "whu" "fdu")

echo "第一个元素为：${schools[0]}"
echo "第二个元素为：${schools[1]}"
echo "第三个元素为：${schools[2]}"

# 获取数组中的所有元素
echo "schools:${schools[@]}"
echo "schools:${schools[*]}"

# 获取数组长度
echo "数组元素个数为（使用*）：${#schools[*]}"
echo "数组元素个数为（使用@）：${#schools[@]}"
