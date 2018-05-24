#########################################################################
# File Name: test.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sun 04 Jun 2017 02:17:49 PM CST
#########################################################################
#!/bin/bash


for i in `seq 22`; do
	./client_tcp 10000 &
done
