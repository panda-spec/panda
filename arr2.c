#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*二维数组*/
void test1()
{
	int arr[3][3] = 
	{
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};
	int arr1[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[][3] = { 1,2,3,4,5,6,7,8,9 };
	// 指向第一行数组指针
	int (*p)[3] = arr;
	printf("%d\n", *(*p + 5)); // 6 
	printf("%d\n", *(*(p + 1) + 2)); // 6
	printf("%d\n", p[1][2]); // 6
	
	// 取地址
	printf("%d\n", &arr);
	printf("%d\n", &arr+1);
	int (*k)[3][3] = &arr;
}
void printArray( int (*p)[3], int len1, int len2 )
{
	for ( int i=0; i < len1; i++ )
	{
		for ( int j=0; j < len2; j++ )
		{
			printf("%d ", p[i][j]);
			printf("%d ", *(*(p + i)+j));
		}
		printf("\n");
	}
}
/*二维数组传参*/
void test2()
{
	int arr[3][3] = 
	{
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};
	printArray(arr,3,3);
}
int main()
{
	test2();
	return 0;
}