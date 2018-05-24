#########################################################################
# File Name: ssh.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Mon 29 May 2017 08:49:38 AM CST
#########################################################################

#!/usr/bin/expect -f

set timeout -1

spawn ssh zhu@172.16.70.130

expect "*password: "

send "070832\n"

expect "*$"

interact """"""

