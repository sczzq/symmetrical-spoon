/*************************************************************************
	> File Name: defs.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 29 May 2017 12:33:14 PM CST
 ************************************************************************/

#ifndef _DEFS_H__
#define _DEFS_H__

#define MIN_VERSION 1
#define MAJOR_VERSION 1

#define VERSION "1.0.1"

struct autotools{
	char *name;
	char *longname;
	char *url;
	char *path;
	char *version;
};

#define CMD_SHOW  1
#define CMD_SEARCH 2 
#define CMD_ADD    3
#define CMD_RELEASE 4

struct node{
	struct autotools * node;
	struct autotools * prev;
	struct autotools * next;
};

struct list{
	struct node * head;
	struct node * tail;
};

#define HASFOUND  0
#define NOTFOUND  1
#define ISEQUALS  3
#define NOTEQUALS  4

struct list root;

#endif

