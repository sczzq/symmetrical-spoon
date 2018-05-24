#include <stdio.h>
int main()
{
	unsigned int a = 1<<20;
	unsigned int b = 0 - a;
	printf("a=%u\n", a);
	printf("a=0x%x\n", a);
	printf("b=%u\n", b);
	printf("b=0x%x\n", b);

	a=1;b=2;
	unsigned int c = a - b;
	printf("1-2=%x\n", c);
	c = b - a;
	printf("2-1=%x\n", c);

	a = 0x3f914584;
	b = 0xffffffff;
	c = a - b;
	printf("%x-%x=%x\n", a, b, c);

	a = 0x3f914584;
	b = 0x3f914585;
	c = a + b;
	printf("%x+%x=%x\n", a, b, c);

	int bits = 32;
	unsigned int range = 0xffffffff;
	unsigned int code = 0x3f914584;
	while(--bits){
		range >>=1;
		code -= range;
		printf("range=%x, code=%x\n", range, code);
		unsigned int t = 0 - ((unsigned int)code >> 31);
		code += range & t;
		
		printf("range=%x, code=%x, t=%x\n", range, code, t);
	}
	
	return 0;
}
