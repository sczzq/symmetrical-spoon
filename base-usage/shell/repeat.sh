#!/bin/bash
repeat()
{
	while :
	do
		$@ && return;
		sleep 2
	done
}

repeat $*

