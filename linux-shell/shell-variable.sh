#!/bin/bash

# 测试命名
# for file in `ls /etc`;do
# 	echo ${file}
# done
# for file in $(ls /etc);do
# 	echo ${file}
# done

# 使用变量
echo "----define and use variable----"
my_name="hgs"
echo "my_name="$my_name
echo "my_name="${my_name}

for skill in Java Python C; do
	echo "I am good at ${skill}."
done

# 重新赋值
echo "----re-assign value----"
your_name="tom"
echo "your_name="${your_name}
your_name="Linus"
echo "your_name="${your_name}

# 只读变量
echo "----readonly variable----"
myUrl="https://www.hegongshan.com"
echo "myUrl="${myUrl}
readonly myUrl
myUrl="hegongshan.github.io"

# 删除变量
echo "----remove variable----"
homepage="hegongshan.github.io"
echo "homepage="${homepage}
unset homepage
echo "homepage="${homepage}

# 字符串操作
echo "----string operation----"
your_name='Xiangnan He'
str="Hello, I know you are \"${your_name}\"! \n"
echo -e ${str}

echo "----concatenation----"
your_name="runoob"
greeting="hello, "${your_name}" !"
greeting1="hello, ${your_name} !"
echo "Double quotes:" ${greeting} ${greeting1}
greeting2='hello, '${your_name}' !'
greeting3='hello, ${your_name} !'
echo 'apostrophe:' ${greeting2} ${greeting3}

string="abcd"
echo ${string}" length is "${#string}
string="runoob is a great site"
echo "substring:"${string:1:4}
# 值从1开始
echo `expr index "${string}" io`

# 数组
echo "----array----"
school=(ccnu whu fudan)
echo ${school[0]}
echo ${school[@]}
# 返回第一元素的值
echo ${school}

echo "array length by @ =" ${#school[@]}
echo "array length by * =" ${#school[*]}
echo "ccnu length =" ${#school[0]}

# 注释
:<<EOF
注释内容
注释内容
EOF


:<<!
注释内容...
注释内容...
!

# Runoob错误地添加了<<
: '
多行注释
多行注释
'
