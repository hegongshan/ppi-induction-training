#!/bin/bash

echo "----Shell 流程控制----"

echo "--测试if...elif...else结构--"
a=10
b=20
if [[ $a == $b ]]; then
	echo "$a等于$b"
elif [[ $a -gt $b ]]; then
	echo "$a大于$b"
elif [[ $a -lt $b ]]; then
	echo "$a小于$b"
else
	echo "没有符合的条件"
fi


echo "--测试if...else + test--"
num1=$[2*3]
num2=$[1+5]
if test $num1 -eq $num2; then
	echo "$num1等于$num2"
else
	echo "$num1不等于$num2"
fi


echo "--测试for循环--"
for i in 1 2 3; do
	echo "The value is $i"
done

for str in This is a string; do
	echo $str
done


echo "--测试while循环--"
c=1
while [[ c -le 5 ]]; do
	echo $c
	let "c++"
done

echo -n "请输入您最喜欢的网站:"
while read site; do
	echo "${site}是一个很好的网站"
done


echo "--测试util循环--"
a=0
until [[ ! a -lt 3 ]]; do
	echo $a
	# let "a++"
	a=`expr $a + 1`
done


echo "--测试case--"
echo '输入 1 到 4 之间的数字:'
read num
case $num in
    1) 
		echo '你选择了 1'
    	;;
    2) 
		echo '你选择了 2'
    	;;
    3)  
		echo '你选择了 3'
    	;;
    4)  
		echo '你选择了 4'
    	;;
    *)  
		echo '你没有输入 1 到 4 之间的数字'
    	;;
esac

site="google"
case $site in
   "runoob") 
		echo "菜鸟教程"
   		;;
   "google") 
		echo "Google 搜索"
   		;;
   "taobao") 
		echo "淘宝网"
   		;;
esac


echo "--测试break和continue--"
while :
do
    echo -n "输入 1 到 3 之间的数字:"
    read num
    case $num in
    	# 多个模式匹配..|..|..)
        1|2|3) 
			echo "你输入的数字为 $num!"
        	;;
        *) 
			echo "你输入的数字不是 1 到 3 之间的! 游戏结束"
            break
    esac
done

while :
do
    echo -n "输入 1 到 3 之间的数字: "
    read num
    case $num in
        1|2|3) 
			echo "你输入的数字为 $num!"
        	;;
        *) 
			echo "你输入的数字不是 1 到 3 之间的!"
            continue
            echo "游戏结束"
        	;;
    esac
done