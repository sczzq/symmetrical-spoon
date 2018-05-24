#########################################################################
# File Name: test.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Mon 22 May 2017 09:13:01 PM CST
#########################################################################
#!/bin/bash

for a in `seq 10000`;
do
	usleep 1
	./asio_daytime_client 127.0.0.1
done
