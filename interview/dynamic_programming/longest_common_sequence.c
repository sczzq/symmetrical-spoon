// longest common sequence
// use dynamic program
//

#include "../header.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define max(x,y) ((x) > (y) ? (x) : (y))

void print_lcs(int *b, char *s1, int len1, int len2, int i, int j)
{
	if (i < 0 || j < 0)
	{
		return;
	}
	int index = i*len2 + j;
	if (b[index] == 'n')
	{
		print_lcs(b, s1, len1, len2, i-1, j-1);
		printf("i: %d, j:%d, %c\n", i, j, s1[i]);
	}
	else if(b[index] == 'u')
		print_lcs(b, s1, len1, len2, i-1, j);
	else
		print_lcs(b, s1, len1, len2, i, j-1);
}

void show_b(int *b, int len1, int len2)
{
	printf("len1: %d, len2: %d\n", len1, len2);
	for(int i = 0; i < len1; i++)
	{
		printf("%d: ", i);
		for(int j = 0; j < len2; j++)
			printf("%c ", b[i*len2+j]);
		printf("\n");
	}
}

int longest_common_sequence(char *s1, char *s2, char *lcs)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int result = 0;

//	int b[len1+1][len2+1];
	int c[len1+1][len2+1];

	int *b = malloc(len1*len2*sizeof(int));

	// get result space.
	for(int i = 0; i <= len1; i++)
	{
		for(int j = 0; j <= len2; j++)
		{
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			} else if (s1[i-1] == s2[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				result = max(c[i][j], result);
				b[(i-1)*len2 + j -1] = 'n';
//				b[i-1][j-1] = 'n'; // new one.
//				printf("s1 pos: %d, s2 pos: %d, char: %c\n", i, j, s1[i-1]);
			} else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[(i-1)][j];
				b[(i-1)*len2 + j -1] = 'u';
//				b[i-1][j-1] = 'u'; // up
//				printf("s1 pos: %d, s2 pos: %d, char: %c\n", i, j, s1[i-1]);
			} else {
				c[i][j] = c[i][j-1];
				b[(i-1)*len2 + j -1] = 'l';
//				b[i-1][j-1] = 'l'; // left
//				printf("s1 pos: %d, s2 pos: %d, char: %c\n", i, j, s1[i-1]);
			}
		}
	}

	show_b(b, len1, len2);
	
	print_lcs(b, s1, len1, len2, len1-1, len2-1);
	printf("\n");

	printf("result:%d,c[%d][%d]:%d\n", result,
			len1, len2, c[len1][len2]);

	return result;
}

#define LENGTH  19
int lcs_test()
{
	char s1[LENGTH], s2[LENGTH], s3[LENGTH];
	memset(s1,0,LENGTH);
	memset(s2,0,LENGTH);
	memset(s3,0,LENGTH);

	random_string(s1,LENGTH-1);
	random_string(s2,LENGTH-1);

	int lcs = longest_common_sequence(s1,s2,s3);
	printf("s1:%s\n", s1);
	printf("s2:%s\n", s2);
	printf("%d\n", lcs);

	char *s4 = "abcab";
	char *s5 = "abccd";
	lcs = longest_common_sequence(s4,s5,s3);
	printf("s4:%s\n", s4);
	printf("s5:%s\n", s5);
	printf("%d\n", lcs);
}
/*
*/
int main()
{
	lcs_test();
}
