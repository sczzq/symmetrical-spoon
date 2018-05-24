#########################################################################
# File Name: token.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Thu 01 Mar 2018 09:47:03 PM CST
#########################################################################
#!/bin/bash

t(){
	echo 0
}

ta () {
	a=1
	echo 1
	return 1
}

tb (){
	b=2
	echo 2
	return 1
}

fa (){
	a=3
	echo 3
	return 0
}

fb (){
	b=4
	echo 4
	return 0
}

#fa = 0 && fb = 0 && ta = 1 && tb = 1

fa && fb

expr test ta | tb

echo $a $b

