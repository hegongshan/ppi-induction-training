#!/bin/bash

echo "----echo命令----"

echo "Hello world!"
echo Hello world!

# 转义字符
echo "--转义字符--"
echo "\"Hello world!\""
echo \"Hello world!\"

# 显示变量
echo "--显示变量--"
read name
echo "Hello ${name}!"

# 换行与否
echo "--显示换行--"
echo -e "OK! \n"
echo "Hello world!"

echo "--显示不换行--"
echo -e "OK! \c"
echo "Hello world!"

echo "--显示结果定向至文件--"
echo "Hello world!" > test-shell-echo.txt

echo "--原样输出字符串，不进行转义或取变量"
echo '$name\"'

echo "--显示命令执行结果--"
# 使用反引号
echo `date`