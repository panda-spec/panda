#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
	char *p = (char *)malloc(128);
	char *q = p;
	for (int i=0; i < 10; i++)
	{
		*q = 97 + i;
		q++;
	}
	printf("p = %s\n", p);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
int main()
{
	test1();
	return 0;
}