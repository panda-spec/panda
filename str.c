#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 方式一
void copyStr(char *dst, char *source)
{
	int len = strlen(source);
	for (int i=0; i < len; i++)
	{
		dst[i] = source[i];
	}
	dst[len] = '\0';
}
// 方式二
void copyStr1(char *dst, char *source)
{
	// 利用指针地址增长
	while (*source != '\0')
	{
		*dst = *source;
		source++;
		dst++;  // 指针指向的是字符串首字母地址,char*每次递增1指向的地址就往后1位
	}
	*dst = '\0';
}
// 方式三
void copyStr2(char *dst, char *source)
{
	// 由于后++是先赋值再++,当source取到'\0'时直接赋值给dst,while循环表达式为*dst=0会停止
	while (*dst++ = *source++)
	{}
}
void test1()
{
	char *str = "hello world";
	char buf[128];
	
	copyStr(buf, str);
}
// 字符串反转
void reserveStr(char *str)
{
	int start = 0;  // 字符串起始位置
	int end = strlen(str) - 1;  // 字符串结束位置
	// 一
	for (int i=0; i < strlen(str); i++)
	{
		if (start < end)
		{
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
		}
	}
	// 二
	while (start < end)
	{
		char temp = str[start];
		str[satrt] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
void test2()
{
	// 字符串反转
	char str[] = "hello world";
	reserveStr(str);
}
void test3()
{
	// 格式化字符串
	char buf[1024] = {0};
	sprintf(buf,"hello %s,welcome to my contry!", "panda");
	printf("buf: %s\n", buf);
	
	memset(buf,0,1024);
	char str1[] = "hello";
	char str2[] = "world";
	int len = sprintf(buf, "%s %s", str1, str2);
	printf("buf: %s len:%d\n", buf, len);
	
	// 数字转字符串
	memset(buf,0,1024);
	int a = 100;
	sprintf(buf, "%d", a);
	printf("buf:%s\n", buf);
	
	// 设置宽度 右对齐
	memset(buf,0,1024);
	sprintf(buf,"%8d",a);
	printf("buf:%s\m",buf);
	
	// 设置宽度 左对齐
	memset(buf,0,1024);
	sprintf(buf,"%-8d",a);
	printf("buf:%d\n",buf);
}
int main()
{
	return 0;
}