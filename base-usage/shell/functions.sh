#!/bin/bash
fname()
{
	echo $1, $2   # accessing arg1 and arg2
	echo "$@"     # print all arguments as list at once
	echo "$*"     # similar to $@, but arguments taken as single entity
	return 0      # return value
}

fname 2 3 4 5 6 7 7 
