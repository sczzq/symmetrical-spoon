#########################################################################
# File Name: case.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 03 Mar 2018 11:06:50 AM CST
#########################################################################
#!/bin/bash

a=abcd

echo ---------------------
case $a in
	ab* ) echo started by ab;;
	bc* ) echo started by bc;;
	* ) echo unknown;;
esac

echo ---------------------
case $a in
	ab* ) echo started by ab;&
	bc* ) echo started by bc;&
	* ) echo no;;
esac

echo ---------------------
case $a in
	ab* ) echo started by ab;;&
	bc* ) echo started by bc;;&
	* ) echo no;;
esac
echo ---------------------

