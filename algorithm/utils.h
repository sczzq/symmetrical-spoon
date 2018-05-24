/*************************************************************************
	> File Name: utils.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 17时08分32秒
 ************************************************************************/

#ifndef __SCZZQ_UTILS_H
#define __SCZZQ_UTILS_H

#define DEBUG

#ifdef DEBUG
#define debug_print(...) printf(__VA_ARGS__);
#define PR(X, ...)	printf("Message " #X ":" __VA_ARGS__);
#else
#define debug_print(format, ...)
#define PR(X, ...)
#endif

#endif

