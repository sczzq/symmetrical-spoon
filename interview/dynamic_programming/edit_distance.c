#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "utility.h"
#include "../header.h"

#define min(x,y) ((x) < (y) ? (x) : (y))

int EditDistance(char *src, char *dst)
{
	if ((strlen(src) == 0) || strlen(dst) == 0)
		return abs(strlen(src) - strlen(dst));

	if(src[0] == dst[0])
		return EditDistance(src+1, dst+1);

	int edIns = EditDistance(src, dst+1);
	int edDel = EditDistance(src+1, dst) + 1;
	int edRep = EditDistance(src+1, dst+1) + 1;

	return min(min(edIns, edDel), edRep);
}

int ed_test1()
{
	int length = 20;
	char s1[length], s2[length];
	memset(s1, 0, length);
	memset(s2, 0, length);

	random_string(s1, length-1);
	random_string(s2, length-1);

	/*
	{
		// too long time.
		START_TIME;
		int el = EditDistance(s1, s2);
		END_TIME;
		printf("s1:%s\n", s1);
		printf("s2:%s\n", s2);
		printf("edit distance: %d\n", el);
	}
	*/

	{
		START_TIME;
		int lcs = longest_common_sequence(s1, s2, NULL);
		END_TIME;
		printf("lcs:%d\n", lcs);
	}
}

int main()
{
	ed_test1();
}
