#!/bin/bash

echo "----Shell 基本运算符----"

echo "----算术运算----"
# 使用反引号
val=`expr 3 + 3`
echo "3 + 3 : ${val}"

a=10
b=20
echo "a=${a}, b=${b}"

val=`expr $a + $b`
echo "a + b : ${val}"

val=`expr $a - $b`
echo "a - b : ${val}"

val=`expr $a \* $b`
echo "a * b : ${val}"

val=`expr $b / $a`
echo "b / a : ${val}"

val=`expr $b % $a`
echo "b % a : ${val}"

# 运算符左右，以及[]均需要添加空格
if [ $a == $b ]
then
	echo "a等于b"
fi

if [ $a != $b ]
then
	echo "a不等于b"
fi

echo "----关系运算符----"
# ==
if [ $a -eq $b ]
then
	echo "$a -eq $b : 成立，a等于b"
else
	echo "$a -eq $b : 不成立，a不等于b"
fi

# !=
if [ $a -ne $b ]
then
	echo "$a -ne $b : 成立，a不等于b"
else
	echo "$a -ne $b : 不成立，a等于b"
fi

# >
if [ $a -gt $b ]
then
	echo "$a -gt $b : 成立，a大于b"
else
	echo "$a -gt $b : 不成立，a不大于b"
fi

# <
if [ $a -lt $b ]
then
	echo "$a -lt $b : 成立，a小于b"
else
	echo "$a -lt $b : 不成立，a不小于b"
fi

# >=
if [ $a -ge $b ]
then
	echo "$a -ge $b : 成立，a大于或等于b"
else
	echo "$a -ge $b : 不成立，a小于b"
fi

# <=
if [ $a -le $b ]
then
	echo "$a -le $b : 成立，a小于或等于b"
else
	echo "$a -le $b : 不成立，a大于b"
fi

# 布尔运算
echo "----布尔运算----"
# a < 100 && b > 15
if [ $a -lt 100 -a $b -gt 15 ]
then
	echo "$a < 100 并且 $b > 15 成立"
else
	echo "$a < 100 并且 $b > 15 不成立"
fi

# a < 100 || b > 100
if [ $a -lt 100 -o $b -gt 100 ]
then
	echo "$a < 100 或 $b > 100 成立"
else
	echo "$a < 100 或 $b > 100 不成立"
fi

# a < 5 || b > 100
if [ $a -lt 5 -o $b -gt 100 ]
then
	echo "$a < 5 或 $b > 100 成立"
else
	echo "$a < 5 或 $b > 100 不成立"
fi
