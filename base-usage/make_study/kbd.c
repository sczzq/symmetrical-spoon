/*************************************************************************
	> File Name: kbd.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 29 May 2017 02:53:25 PM CST
 ************************************************************************/

#include "defs.h"
#include "command.h"

int kbd()
{
	struct autotools* at;
	char a = getchar();
	int cmd = a - '0';
	switch(cmd){
	case CMD_ADD:
		get();
		command_add();
		break;
	case CMD_SHOW:
		command_show();
		break;
	case CMD_SEARCH:
		command_search();
		break;
	case CMD_RELEASE:
		command_release();
		break;
	default:
		help();
		break;
	}
	getchar();

	return 1;
}

