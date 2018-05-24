
#include "primer.h"
#include <stdio.h>

char *getnchar(char *array, int n)
{
	int i=0;
	while(n--)
		array[i++] = getchar();
	return array;
}

int getnc(char *array, int n)
{
	int i=0;
	char c;
	while((n--) && (c=getchar()) != ' ' && (c != '\t') && (c != '\n'))
		array[i++] = c;
	return i;
}

char *getstr(char *array)
{
	char c;
	int i=0;

	while((c=getchar()) != ' ' && (c != '\t') && (c != '\n'))
		array[i++] = c;

	array[i] = '\0';

	while( c != '\n' )
		c = getchar();

	return array;
}

char *strsearch(char *deck, char *target)
{
	int start=0, dl, tl;
	dl = strlen(deck);
	tl = strlen(target);
	while(dl - start - tl >= 0){
		if(!strncmp(deck+start, target, tl)){
			break;
		} else {
			start++;
		}
	}
	if(dl - start - tl >= 0){
		return deck+start;
	} else {
		return NULL;
	}
}

int charsearch(char c, const char *s)
{
	if(c=='\0')
		return 1;
	while(*s)
		if(*s==c)
			break;
		else
			s++;
	if(*s)
		return 1;
	else
		return 0;
}

int stringreverse(char *s)
{
	int sl, i=0;
	char c;
	sl = strlen(s);
	while(i<sl/2){
		c = s[i];
		s[i] = s[sl-i-1];
		s[sl-i-1] = c;
		i++;
	}
	return 0;
}
void show_1()
{
	printf("%s\n", __func__);
}
void show_2()
{
	printf("%s\n", __func__);
}
void show_3()
{
	printf("%s\n", __func__);
}
void show_4()
{
	printf("%s\n", __func__);
}
void show_5()
{
	printf("%s\n", __func__);
}
#define N      10
#define LENGTH 80
#define HELP "1: output initial strings\n" \
	     "2: output strings as order ASCII\n" \
	     "3: output strings as order by string's length\n" \
	     "4: output strings as order by first word's length\n" \
	     "5: quit or break\n" \
	     "--------------------\n"
void show(void)
{
	char s[N][LENGTH];
	int i=0, j=0, n=LENGTH;
	int q=0;
	char c;
	while(i<N){
		j = 0;
		n = LENGTH;
		while((n--) && (c=getchar()) != '\n' && (c != EOF))
			s[i][j++] = c;
		s[i][j++] = '\0';
		if( c == EOF )
			break;
		i++;
	}
	while(1){
		printf("%s\n", HELP);
		c = getchar();
		while(getchar() != '\n')
			continue;
		switch(c) {
			case '1':
				show_1();
			break;
			case '2':
				show_2();
			break;
			case '3':
				show_3();
			break;
			case '4':
				show_4();
			break;
			case '5':
				show_5();
				q = 1;
			break;
			default:
				printf("unrecognize character\n");
			break;
		}
		if( q == 1)
			break;
	}
}

