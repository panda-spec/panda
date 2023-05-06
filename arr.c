#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*一维数组*/
void test1()
{
 	// 一维数组名不是指向首元素地址的指针
 	int arr[5] = {1,2,3,4,5};
 	printf("sizeof arr = %d\n", sizeof(arr));
 	
 	// 数组名取地址
 	printf("%p\n", &arr);
 	printf("%p\n", &arr + 1);  // 跨过一个数组长度
 	
 	// 指向数组首元素地址指针
 	int *p = arr;
 	// 指针常量,int *const p
 	// arr = NULL; 指针的指向不能修改
 	arr[0] = 100; // 指针的值可以修改
 	
 	// 数组访问的时候下标可以为负数
 	p = p + 3;
 	printf("%d\n",p[-1]);
}
void printArray( int arr[], int len )
{
	for ( int i=0; i < len; i++ )
	{
		printf("%d\n", arr[i]);
		printf("%d\n", *(arr + i));
	}
}
/*一维数组传参*/
void test2()
{
	int arr[3] = { 1,2,3 };
	int len = sizeof(arr)/sizeof(int);
	printArray(arr, len);
}
/*定义数组指针*/
void test3()
{
	int arr[5] = { 1,2,3,4,5 };
	// 定义5个int元素的数组类型
	typedef int(ARRAY_TYPE)[5];
	
	ARRAY_TYPE *p = &arr;
	for ( int i=0; i < 5; i++ )
	{
		printf("%d\n", (*p)[i]);
	}
	
	// 先定义数组指针
	typedef int(*ARRAY_TYPE)[5];
	ARRAY_TYPE q = &arr;
	for ( int i=0; i < 5; i++ )
	{
		printf("%d\n", *q[i]);
	}
}
/*直接定义数组指针变量*/
void test4()
{
	int arr[4] = { 1,2,3,4 };
	int (*p)[4] = &arr;
	for ( int i=0; i < 5; i++ )
	{
		printf("%d\n", (*p)[i]);
	}
}
int main()
{
	test1();
	return 0;
}