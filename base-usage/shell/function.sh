#########################################################################
# File Name: function.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Fri 02 Mar 2018 09:42:35 PM CST
#########################################################################
#!/bin/bash

FUNCNEST=10

t=0

test ( )
{
	let t=$t+1
	echo $t
	test 1
}

test 1 2

echo --------------

test 1 2 3

echo -------------------

echo $FUNCNEST


