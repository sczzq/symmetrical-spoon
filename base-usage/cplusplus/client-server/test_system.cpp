/*************************************************************************
	> File Name: test_system.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 08:05:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
int main(void) {
	int ret;
	ret = system("ping www.baidu.com");
	printf("%d\n", ret);
	return 0;
}
