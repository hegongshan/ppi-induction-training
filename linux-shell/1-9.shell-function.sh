#!/bin/bash

echo "----Shell函数----"

test(){
	echo "测试shell函数！"
}

test


testReturn(){
	echo "请输入一个数字"：
	read numA
	echo "请再输入一个数字"：
	read numB
	echo "输入的数字为$numA和$numB"
	return `expr $numA + $numB`
}
testReturn
echo "两个数字之和为$?"


testArguments(){
	echo "第一个参数为$1"
	echo "第二个参数为$2"

	echo "不加括号：第十个参数为$10"
	echo "加括号：第十个参数为${10}"

	echo "参数个数为$#"
	echo "全部的参数为：$*"
}
testArguments 1 2 3 4 5 6 7 8 9 100
