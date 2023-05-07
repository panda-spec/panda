#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char *name;
	int age;
};
struct Person **allocateSpace()
{
	// 给结构体指针数组分配空间
	struct Person **tmp = malloc(sizeof(struct Person *)*3);
	for ( int i=0; i < 3; i++ )
	{
		// 给每个结构体指针分配空间
		tmp[i] = malloc(sizeof(struct Person));
		// 给结构体成员分配空间
		tmp[i]->name = malloc(sizeof(char)*64);
		// 给成员赋值
		sprintf(tmp[i]->name, "name_%d", i+1);
		tmp[i]->age = 10 + i;
	}
	// 返回结构体指针数组
	return tmp;
}
void printArray( struct Person **arr, int len )
{
	for ( int i=0; i < len; i++ )
	{
		printf("name=%s age=%d\n", arr[i]->name, arr[i]->age);
	}
}
void freeSpace( struct Person **arr, int len )
{
	if ( arr == NULL || len <=0 )
	{
		return;
	}
	for ( int i=0; i < len; i++ )
	{
		if ( arr[i]->name != NULL )
		{
			free(arr[i]->name);
			arr[i]->name = NULL;
		}
		if ( arr[i] != NULL )
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	free(arr);
	arr = NULL;
}
void test01()
{
	struct Person **pArray = NULL;
	pArray = allocateSpace();
	// 打印
	printArray(pArray,3);
	// 释放
	freeSpace(pArray,3);
	// 同级指针需要手动置空
	pArray = NULL;
}
int main()
{
	test01();
	return 0;
}
