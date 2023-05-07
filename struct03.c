#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*老师结构体*/
struct Teacher
{
	char *name;
	char **stu;
};

struct Teacher **allocateSpace()
{
	// teacher 分配空间
	struct Teacher **teacherArray = malloc(sizeof(struct Teacher *)*3);
	for ( int i=0; i < 3; i++ )
	{
		// 给老师分配空间
		teacherArray[i] = malloc(sizeof(struct Teacher));
		// 给老师属性分配空间
		teacherArray[i]->name = malloc(sizeof(char)*64);
		// 给姓名赋值
		sprintf(teacherArray[i]->name, "TeacherName_%d", i+1);
		// 给老师的学生数组分配空间
		teacherArray[i]->stu = malloc(sizeof(char *)*4);
		// 给学生姓名赋值
		for ( int j=0; j < 4; j++ )
		{
			teacherArray[i]->stu[j] = malloc(sizeof(char)*64);
			sprintf(teacherArray[i]->stu[j], "%s_StudentName_%d", teacherArray[i]->name, j+1);
		}
	}
	return teacherArray;
}
void printInfo( struct Teacher **arr, int len )
{
	if ( arr == NULL || len <=0 )
	{
		return;
	}
	for ( int i=0; i < len; i++ )
	{
		printf("teacher's name is: %s\n", arr[i]->name);
		for ( int j=0; j < 4; j++ )
		{
			printf("student's name is: %s\n", arr[i]->stu[j]);
		}
	}
}
void freeSpace( struct Teacher **arr, int len )
{
	if ( arr == NULL || len <=0 )
	{
		return;
	}
	for ( int i=0; i < len; i++ )
	{
		if ( arr[i]->name != NULL )
		{
			printf("%s被释放了\n",arr[i]->name);
			free(arr[i]->name);
			arr[i]->name = NULL;
		}
		for ( int j=0; j < 4; j++ )
		{
			if ( arr[i]->stu[j] != NULL )
			{
				printf("%s被释放了\n",arr[i]->stu[j]);
				free(arr[i]->stu[j]);
				arr[i]->stu[j] = NULL;
			}
		}
		if ( arr[i]->stu != NULL )
		{
			printf("学生数组被释放了\n");
			free(arr[i]->stu);
			arr[i]->stu = NULL;
		}
		if ( arr[i] != NULL )
		{
			printf("老师数组被释放了\n");
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	printf("整体释放\n");
	free(arr);
	arr = NULL;
}
void test01()
{
	struct Teacher **pArray = NULL;
	pArray = allocateSpace();
	// 打印
	printInfo(pArray, 3);
	// 释放
	freeSpace(pArray, 3);
	pArray = NULL;
}
int main()
{
	test01();
	return 0;
}