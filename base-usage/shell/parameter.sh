#########################################################################
# File Name: parameter.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 03 Mar 2018 12:09:13 PM CST
#########################################################################
#!/bin/bash

a=a

${b:?"no b parameter definition"}

echo $a
