/*************************************************************************
	> File Name: cpp_diagnostics.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 13 Mar 2018 08:42:21 PM CST
 ************************************************************************/

#include "stdio.h"

#ifdef __vax__
#error "won't work on VAXen, See comments at get_last_object"
#endif

#ifdef __linux__
#warning "this is linux machine"
#endif

#ifdef __unix__
#warning "this is unix machine"
#endif

#ifdef __cplusplus
#warning "this is cplusplus environment"
#endif

int main()
{
	printf("Test\n");
}
