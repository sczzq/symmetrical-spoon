#########################################################################
# File Name: blank.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 03 Mar 2018 11:18:36 AM CST
#########################################################################
#!/bin/bash

[[ hello =~ \.* ]]
echo $?

[[ hello =~ 'hello' ]]
echo $?

[[ hello =~ \.*llo ]]
echo $?

[[ hello =~ \.+l+o ]]
echo $?

test ()
{
	echo hello
}

declare -f

