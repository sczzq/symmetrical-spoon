#!/bin/bash
subshell()
{
	count=0;
	while [ $count -lt 5 ]
	do
	sleep 1;
	echo 1;
	let count=$count+1;
	done;
}
pwd;
#(
cd ..; 
#ls;
subshell
#)
pwd;

