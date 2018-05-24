/*************************************************************************
	> File Name: sigsegv.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 05 Jun 2017 10:10:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void sigsegv_handler(int sig)
{
	printf("get sigsegv signals\n");
}

int main()
{
	struct sigaction sa, oldsa;

	memset(&sa, 0, sizeof(sa));
	memset(&oldsa, 0, sizeof(oldsa));
	sa.sa_handler = &sgsegv_handler;
	sa.sa_mask = SIGSEGV;
	sa.sa_flags = SA_NODEFER;
	

}
