#!/bin/bash
#Filename: remove_duplicates.sh
#Description: Find and remove duplicate files and keep one sample of each file
# Bug: if duplicate files are three, then just remove one duplicate file, and also have two files.
#      maybe caused by awk. And now not know how to exactly use awk.

# Issue: deal symbol link file as regular file.

duplicate_files=`mktemp`
duplicate_sample=`mktemp`
ls -lS --time-style=long-iso | awk 'BEGIN {
	getline; getline;
	name1=$8; size=$5
}
{
	name2=$8;
	if(size==$5)
	{
		"md5sum "name1 | getline; csum1=$1;
		"md5sum "name2 | getline; csum2=$1;
		if ( csum1 == csum2 )
		{
			print name1; print name2;
		}
	};
	size=$5; name1=name2;
}' | sort -u > $duplicate_files

files=`wc -l $duplicate_files | awk '{ print $1 }'`
#echo $files
if [ "$files" -eq 0 ]; then
	echo No duplicate file
	exit 0
fi

cat $duplicate_files | xargs -I {} md5sum {} | sort | uniq -w 32 | awk '{ print $2 }' | sort -u > $duplicate_sample

echo Removing..

comm $duplicate_files $duplicate_sample -2 -3 | tee /dev/stderr | xargs rm

echo Removed deplicates files successfully.

