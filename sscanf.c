#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
	char *str = "12345abcde";
	char buf[128] = {0};
	sscanf(str,"%*d%s",buf);  // 跳过数字字符,拷贝到buf
	printf("buf=%s\n", buf);
	
	char *str1 = "abcd1234";
	memset(buf,0,128);
	sscanf(str1, "%*[a-z]%s",buf);
	printf("buf=%s\n", buf);
}
void test2()
{
	// %[width]s 读指定宽度数据
	char *str = "asbdha1234";
	char buf[128] = {0};
	sscanf(str,"%7s", buf);
	printf("buf=%s\n", buf);
}
void test3()
{
	char *p = "127.0.0.1";
	int n1, n2, n3, n4;
	sscanf(p,"%d.%d.%d.%d",&n1,&n2,&n3,&n4);
}
void test4()
{
	char *p = "shaje$leeon&sajks";
	char buf[128] = {0};
	sscanf(p,"%*[^$]$%[^&]",buf);
	printf("buf=%s\n", buf);
}
int main()
{
	test4();
	return 0;
}