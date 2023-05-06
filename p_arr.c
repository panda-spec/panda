#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort( int arr[], int len )
{
	for ( int i=0; i < len; i++ )
	{
		// 假设下标i为最小值
		int min = i;
		for ( int j=i+1; j < len; j++ )
		{
			if ( arr[min] > arr[j] )
			{
				min = j;
			}
		}
		if ( min != i )
		{
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}
void ()
{
	// 选择排序
	int arr[] = { 2,5,3,7,8 };
	Sort(arr, sizeof(arr)/sizeof(int));	
}
void sortStr( char *arr[], int len )
{
	for ( int i=0; i < len; i++ )
	{
		int max = i;
		for ( int j=i+1; j < len; j++ )
		{
			if ( strcmp( arr[max], arr[j] ) == -1 )
			{
				max = j;
			}
		}
		if ( max != i )
		{
			char *tmp = arr[i];
			arr[i] = arr[max];
			arr[max] = tmp;
		}
	}
}
void test1()
{
	// 指针数组
	char *p[] = { "aaa", "bbb", "ccc", "ddd" };
	int len = sizeof(p)/sizeof(char *);
	sortStr(p, len);
}
int main()
{
	return 0;
}