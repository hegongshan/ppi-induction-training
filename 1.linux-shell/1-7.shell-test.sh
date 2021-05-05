#!/bin/bash

echo "----Shell test命令----"

echo "--数值测试--"
a=100
b=100

if test $a -eq $b
then
	echo "$a等于$b"
else
	echo "$a不等于$b"
fi

# 测试中括号
result=$[a+b]
echo "$a + $b = $result"


echo "--字符串测试--"
s1="ru23noob"
s2="runoob"

if test $s1 = $s2
then
	echo "$s1和$s2相等"
else
	echo "$s1和$s2不相等"
fi


echo "--文件测试--"
cd /bin
if test -e ./bash
then
	echo "/bin/bash已存在！"
else
	echo "/bin/bash不存在！"
fi

cd /bin
if test -e ./bash -o -e ./yum
then
	echo "/bin/bash和/bin/yum至少存在一个！"
else
	echo "/bin/bash和/bin/yum均不存在！"
fi
