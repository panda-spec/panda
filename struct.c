#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char name[64];
	int age;
};
typedef struct Person
{
	char name[64];
	int age;
}myPerson; // 结构体别名
void test1()
{
	myPerson p1 = { "Tom", 18 };
}
struct Person2
{
	char name[64];
	int age;
}myPerson2;  // 结构体变量,可以直接初始化myPerson2 = {"Tom",20};
void test2()
{
	strcpy(myPerson2.name, "spam");
	myPerson2.age = 20;
}
struct 
{
	char name[64];
	int age;
}myPerson3;  // 匿名结构体变量,也能直接初始化myPerson3 = {"Tom",20};
/*结构体分配内存*/
void test3()
{
	// 栈区
	struct Person *p1 = { "李白", 33 };  // 能初始化
	// 堆区
	struct Person *p2 = malloc(sizeof(struct Person));  // 不能直接初始化
	strcpy(p2->name, "苏轼");
	p2->age = 40;
	// 释放
	free(p2);
}
void printPerson( struct Person arr[], int len )
{
	for ( int i=0; i < len; i++ )
	{
		printf("name=%s age=%d\n", arr[i].name, arr[i].age);
	}
}
void test4()
{
	// 结构体数组
	struct Person personArray[] = 
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 }
	};
	// 数组长度
	int len = sizeof(personArray) / sizeof(struct Person);
	// 打印
	printPerson(personArray, len);
	
	// 结构体指针,开辟4个结构体空间
	struct Person *p = malloc(sizeof(struct Person)*4);
	for ( int i=0; i < 4; i++ )
	{
		sprintf(p[i].name, "name_%d", i+1);
		p[i].age = 10+i;  // 给每个结构体中的成员赋值  
	}
}
int main()
{
	return 0;
}