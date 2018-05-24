/*************************************************************************
	> File Name: getprotoent.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 05 Jun 2017 08:18:57 PM CST
 ************************************************************************/

#include <netdb.h>
#include <stdio.h>

void show(struct protoent * p)
{
	if(!p)
		return;
	printf("prototol name : %s,\tp_alianses: ", p->p_name);
	char **pp;
	pp = p->p_aliases;
	int i = 0;
	while(pp[i]){
		printf("%s, ", pp[i++]);
	}
	printf("\tproto: %d\n", p->p_proto);
}

int main()
{
	struct protoent * pent = getprotoent();

	while(pent){
		show(pent);
		pent = getprotoent();
	}

	printf("SOL_SOCKET: %d\n", SOL_SOCKET);

	return 0;
}
