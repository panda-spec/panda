#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search(char *str, char *source)
{
	int num = 0;
	while (*str != '\0')
	{
		if (*str != *source)
		{
			str++;
			num++;
		}
		// 字符串指向的地址字符相等,创建子指针继续比较
		char *tempStr = str;
		char *tempSource = source;
		while (*tempSource != '\0')
		{
			if (*tempStr != *tempSource)
			{
				str++;
				num++;
				break;
			}
			tempStr++;
			tempSource++;
		}
		if (*tempSource == '\0')
		{
			return num;
		}
	}
	return -1;
}
void test1()
{
	char *str = "asgdbdefskals";
	char buf[128] = {0};
	scanf("%s", buf);
	int ret = search(str, buf);
	printf("ret=%d\n",ret);
}
int main()
{
	test1();
	return 0;
}