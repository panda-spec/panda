#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
void func()
{
	char *p1 = NULL;
	double *p2 = NULL;
	printf("%d\n", p1);
	printf("%d\n", p1+1);  // 1 跨过1个字符步长,1个字节
	printf("%d\n", p2);
	printf("%d\n", p2+1); // 8 跨过一个浮点型步长,8个字节
}
void func1()
{
	char buf[1024] = {0};
	int a = 100;
	memcpy(buf, &a, sizeof(int));
	
	char *p = buf;
	printf("%d\n", *(int *)p);
	
	memcpy(buf+1, &a, sizeof(int));
	char *q = buf;
	printf("%d\n", *(int *)(p+1));
}
struct Pw
{
	char a;
	int b;
	char buf[10];
	int c;
};
void func2()
{
	struct Pw a = {'65',2,"hello",100};
// 	char *p = &a;
	// 计算偏移量
	printf("c的偏移量是: %d\n", offsetof(struct Pw, c));
	// 通过偏移量访问属性
	printf("c的值是: %d\n", *(int *)((char *)&a + offsetof(struct Pw,c)));
}

int main()
{
// 	func();
// 	func1();
	func2();
	return 0;
}
