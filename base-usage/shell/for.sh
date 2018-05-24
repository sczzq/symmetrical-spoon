#########################################################################
# File Name: for.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 03 Mar 2018 10:53:58 AM CST
#########################################################################
#!/bin/bash

for arg ; 
do
	echo $arg
done
echo $?

for arg in
do
	echo $arg
done
echo $?
