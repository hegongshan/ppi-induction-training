#!/bin/bash

#测试命名
# for file in `ls /etc`;do
# 	echo ${file}
# done
# for file in $(ls /etc);do
# 	echo ${file}
# done

# 使用变量
my_name="hgs"
echo $my_name
echo ${my_name}

for skill in Java Python C; do
	echo "I am good at ${skill}."
done

# 重新赋值
your_name="tom"
echo $your_name
your_name="Linus"
echo $your_name
