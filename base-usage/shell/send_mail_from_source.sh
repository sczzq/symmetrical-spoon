#########################################################################
# File Name: send_mail_from_source.sh
# Author: ziqiang
# mail: ziqiang_free@163.com
# Created Time: Sat 12 Aug 2017 10:45:27 PM CST
#########################################################################
#!/bin/bash

# send mail from source
# first step, send every source file as mail text,
# second step, send every source as attached file.
# from ziqiang_free@163.com to zhuziqiang@changchong.com.cn 

FROM=ziqiang_free@163.com
TO=zhuziqiang@changchong.com.cn
MAIL=mail
SOURCE_DIR=source/vim/src

for file in `find $SOURCE_DIR -name *.c`; do
	date
	echo send $file from $FROM to $TO
	mail -r $FROM "$file" $TO < $file
	break
done
