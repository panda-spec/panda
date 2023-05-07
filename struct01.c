#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char name[64];
	int age;
};
/*栈区赋值操作(浅拷贝)*/
void test1()
{
	struct Person p1 = { "Tom", 18 };
	struct Person p2 = { "jerry", 19 };
	p1 = p2;
	printf("name=%s age=%d\n", p1.name, p1.age);
	printf("name=%s age=%d\n", p2.name, p2.age);
}
struct Person01
{
	char *name;
	int age;
};
/*堆区赋值操作*/
void test2()
{
	struct Person01 p1;
	p1.name = malloc(sizeof(char)*64);
	strcpy(p1.name, "Tom");
	p1.age = 18;
	struct Person01 p2;
	p2.name = malloc(sizeof(char)*128);
	strcpy(p2.name, "jerry");
	p2.age = 20;
	/*
		直接赋值会导致堆区无法释放造成内存泄露,两个指针指向的堆区空间一样不能重复释放
		p1 = p2;
		if (p1.name != NULL)
		{
			free(p1.name);
			p1 = NULL;
		}
		if (p2.name != NULL)
		{
			free(p2.name);
			p2 = NULL;    p1 p2指向的是同一块内存地址
		}
	*/
	// 再开辟一块堆区拷贝p2数据
	if ( p1.name != NULL )
	{
		free(p1.name);
		p1.name = NULL;
	}
	p1.name = malloc(strlen(p2.name) + 1);
	strcpy(p1.name,p2.name);
	p1.age = p2.age;
	printf("name=%s age=%d\n", p1.name, p1.age);
	printf("name=%s age=%d\n", p2.name, p2.age);
	if ( p1.name != NULL )
	{
		free(p1.name);
		p1.name = NULL;
	}
	if ( p2.name != NULL )
	{
		free(p2.name);
		p2.name = NULL;
	}
}
int main()
{
	test2();
	return 0;
}