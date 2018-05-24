#########################################################################
# File Name: return.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sun 04 Mar 2018 09:24:58 PM CST
#########################################################################
#!/bin/bash

func ()
{
	echo func
	return 1
}

func

return 0
