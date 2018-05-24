#!/bin/bash

#/*************************************************************************
#	> File Name: test_iso_c_header_files.sh
#	> Author: ziqiang
#	> Mail: ziqiang_free@163.com 
#	> Created Time: Sun 05 Nov 2017 12:26:14 PM CST
# ************************************************************************/

ISO_C_='assert.h'
ISO_C_+=' complex.h'
ISO_C_+=' ctype.h'
ISO_C_+=' errno.h'
ISO_C_+=' fenv.h'
ISO_C_+=' float.h'
ISO_C_+=' inttypes.h'
ISO_C_+=' iso646.h'
ISO_C_+=' limits.h'
ISO_C_+=' locale.h'
ISO_C_+=' math.h'
ISO_C_+=' setjmp.h'
ISO_C_+=' signal.h'
ISO_C_+=' stdarg.h'
ISO_C_+=' stdbool.h'
ISO_C_+=' stddef.h'
ISO_C_+=' stdint.h'
ISO_C_+=' stdio.h'
ISO_C_+=' stdlib.h'
ISO_C_+=' string.h'
ISO_C_+=' tgmath.h'
ISO_C_+=' time.h'
ISO_C_+=' wchar.h'
ISO_C_+=' wctype.h'

POSIX_+='aio.h'
POSIX_+=' cpio.h'
POSIX_+=' dirent.h'
POSIX_+=' dlfcn.h'
POSIX_+=' fcntl.h'
POSIX_+=' fnmatch.h'
POSIX_+=' glob.h'
POSIX_+=' grp.h'
POSIX_+=' iconv.h'
POSIX_+=' langinfo.h'
POSIX_+=' monetary.h'
POSIX_+=' netdb.h'
POSIX_+=' nl_types.h'
POSIX_+=' poll.h'
POSIX_+=' pthread.h'
POSIX_+=' pwd.h'
POSIX_+=' regex.h'
POSIX_+=' sched.h'
POSIX_+=' semaphore.h'
POSIX_+=' strings.h'
POSIX_+=' tar.h'
POSIX_+=' termios.h'
POSIX_+=' unistd.h'
POSIX_+=' wordexp.h'
POSIX_+=' arpa/inet.h'
POSIX_+=' net/if.h'
POSIX_+=' netinet/in.h'
POSIX_+=' netinet/tcp.h'
POSIX_+=' sys/mman.h'
POSIX_+=' sys/select.h'
POSIX_+=' sys/socket.h'
POSIX_+=' sys/stat.h'
POSIX_+=' sys/statvfs.h'
POSIX_+=' sys/times.h'
POSIX_+=' sys/types.h'
POSIX_+=' sys/un.h'
POSIX_+=' sys/utsname.h'
POSIX_+=' sys/wait.h'

USR_INCLUDE=/usr/include
GCC_INCLUDE=/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include

check() 
{
	DIR_1=$1
	DIR_2=$2
	shift
	shift
	echo $#
	echo --------------------------------------------
	echo $DIR_1
	echo $DIR_2
	echo --------------------------------------------
	echo -e "file\t\tusr\tgcc"
	while [ $# -gt 0 ]; do
		file=$1
		shift
		echo -n $file

		if [ ${#file} -gt 7 ]; then
			tab="\\t"
		else
			tab="\\t\\t"
		fi

		ls $DIR_1/$file 1>/dev/null 2>/dev/null
		if [ $? == 0 ]; then
			echo -e -n "$tab *"
		else
			echo -e -n "$tab -"
		fi

		ls $DIR_2/$file 1>/dev/null 2>/dev/null
		if [ $? == 0 ]; then
			echo -e -n "\t *"
		else
			echo -e -n "\t -"
		fi
		echo
	done
	echo --------------------------------------------
}

check $USR_INCLUDE $GCC_INCLUDE $ISO_C_
check $USR_INCLUDE $GCC_INCLUDE $POSIX_

