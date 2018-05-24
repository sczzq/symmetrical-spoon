#########################################################################
# File Name: bash.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Thu 25 May 2017 11:22:22 PM CST
#########################################################################
#!/bin/bash

libpthread_version=`getconf GNU_LIBPTHREAD_VERSION`
echo libpthread version $libpthread_version

$(ldd /bin/ls | grep libc.so | awk '{print $3}') | egrep -i 'threads|ntpl'
