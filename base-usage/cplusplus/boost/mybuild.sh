#########################################################################
# File Name: mybuild.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Mon 22 May 2017 05:44:55 PM CST
#########################################################################
#!/bin/bash

BOOSTROOTDIR=/home/zhu/source/boost_1_64_0/
BOOSTLIBDIR=${BOOSTROOTDIR}/stages/lib/

LIB_PREFIX=boost_
LIB_POSFIX=.a

EXE=$1
LIBS=

shift 1
echo $1

for ; do
	LIBS="${LIBS} ${BOOSTBLIDIR}$1${LIB_POSFIX} "
	shift 1
done

echo ${EXE}
echo ${LIBS}

#g++ -I ${BOOSTROOTDIR} $1 



