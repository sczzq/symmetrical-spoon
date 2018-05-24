#########################################################################
# File Name: shell-note.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 12 Aug 2017 09:24:41 AM CST
#########################################################################
#!/bin/bash

# 本文件按顺序执行以下操作
#   1，从远程仓库中更新代码
#   2，编译最新代码
#   3，将编译好的程序打包
#   4，将打包的程序通过邮件发送给相关人员

# 例子：命名规则
# 1，远程仓库路径
REMOTE_SOURCE_DIR=https://github.com/FreeRADIUS/freeradius-server.git
# 2，本地代码根路径
LOCAL_ROOT_DIR=/home/zhu/source/
# 3，本地代码目录名
SOURCE_DIR=freeradius-server
# 4，编译脚本文件名
COMPILE_FILE=compile.sh
# 5，编译后程序包文件名
PACKAGE_FILE=freeradius-server.deb
# 6，邮件地址
ZHU_MAIL=ziqiang_free@163.com
HAN_MAIL=hanyue@163.com
ZHAO_MAIL=zhao@163.com
# 7，sendmail参数，发送每一封邮件都使用的相同的那一部分参数
MAIL_FLAGS= 
# 8，临时路径，用来存放编译打包产生的临时文件和文件夹
TEMP_DIR=/tmp/freeradius-temp


