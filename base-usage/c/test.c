
#include "primer.h"
#include <stdio.h>

//void test_strsearch(void);
//void test_charsearch(void);
//void test_strintreverse(void);

int main(int argc, char *argv[])
{
	char array[20];
	int n=10;
/*
	printf("Input %d character\n", n);
	getnchar(array, n);
	array[n+1] = '\0';
	puts(array);

	printf("Input %d character\n", n);
	getnc(array, n);
	array[n+1] = '\0';
	puts(array);
	printf("Input string\n");
	getstr(array);
	printf("---%s---\n", array);
*/
/*
	n = getnc(array, n);
	n > 0 && (array[n+1] = '\0');
	printf("---%s---\n", array);
*/
//	test_strsearch();
//	test_charsearch();
//	test_strintreverse();
//	show();
	test_FILE();
	return 0;
}
/*
void test_strsearch(void)
{
	int i=0;
	char deck[80] = "Hello world, Artificial Intelligence comes";
	char target[8][20] = {
			"Hello", 
			"world", 
			"coming",
			"world go"
			};
	printf(">>>>>>>>>>>%s>>>>>>>>>>>\n", deck);
	while(i<4){
		printf("<<<<<<<%s<<<<<<<<<<\n", target+i);
		if(strsearch(deck, target[i])){
			printf("%s\n", "findout");
		} else {
			printf("%s\n", "empty");
		}
		i++;
	}
	if(strsearch(target[0], deck)){
		printf("%s\n", "findout");
	} else {
		printf("%s\n", "empty");
	}
}

void test_charsearch(void)
{
	int i=0;
	char *string = "Artificial Intelligence";
	char c[10] = "AaFi ce z\0";
	printf("%s\n", string);
	while(i<10){
		if(charsearch(c[i], string))
			printf("%c--foundout\n", c[i]);
		else
			printf("%c--empty\n", c[i]);
		i++;
	}
}

void test_strintreverse(void)
{
	int i=0;
	char s[3][10] = {"Hello tes",
			 "hello",
			 "   asdf   ",	
			};
	while(i<3){
		printf("%d<<<<<<%s<<<<<\n", i, s[i]);
		stringreverse(s[i]);
		printf("%d>>>>>>%s>>>>>>>\n", i, s[i]);
		i++;
	}
}
*/

