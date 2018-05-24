#include <stdio.h>

int main(void)
{
	int i = 7;
	while(i<100000){
		if(i%2==1 && i%3==0 && i%4==1 & i%5==4 && i%6==3 && i%7==0 && i%8==1 && i%9==0)
			printf("i=%d\n", i);
		i++;
	}
	return 0;
}
