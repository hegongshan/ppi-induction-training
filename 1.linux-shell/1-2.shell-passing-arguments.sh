#!/bin/bash

# 传递参数
echo "----Shell 传递参数实例----"
echo "执行的文件名：$0"
echo "第一个参数为：$1"
echo "第二个参数为：$2"
echo "第三个参数为：$3"

echo "参数的个数为：$#"
echo "传递的参数作为一个字符串显示：$*"

echo "----测试\$*----"
for i in "$*"; do
	echo $i
done

echo "----测试\$@----"
for i in "$@"; do
	echo $i
done
