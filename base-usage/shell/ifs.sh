#########################################################################
# File Name: ifs.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Fri 02 Mar 2018 10:22:20 PM CST
#########################################################################
#!/bin/bash

test()
{
	IFS=a
	echo IFS=$IFS
#	echo ($*)
	echo $*
	echo "$*"
}

test abc efg
