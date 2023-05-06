#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getFileLines(FILE *file)
{
	if (file == NULL)
	{
		perror("open");
		return -1;
	}
	char buf[1024];
	int lines = 0;
	while (fgets(buf,1024,file) != NULL)
	{
		lines++;
	}
	// 将文件光标置首
	fseek(file,0,SEEK_SET);
	return lines;
}
void readFileData(FILE *file, char **pArray, int len)
{
	if (file == NULL || pArray == NULL || len == 0)
	{
		return;
	}
	char buf[1024] = {0};
	int index = 0;
	while (fgets(buf,1024,file) != NULL)
	{
		// 计算每行字符串长度
		int currentLen = strlen(buf) + 1;
		// 字符串\n改为\0
		buf[strlen(buf)-1] = '\0';
		// 开辟每行空间
		char *pCurrent = (char *)malloc(sizeof(char *)*currentLen);
		// 将每行数据放入空间中
		strcpy(pCurrent,buf);
		// 将数据放入数组中
		pArray[index++] = pCurrent;
		// 重置buf数据
		memset(buf,0,1024);
	}
}
void showArray(char **pArray, int len)
{
	for (int i=0; i < len; i++)
	{
		printf("第%d行的数据是: %s\n", i+1, pArray[i]);
	}
}
void freeMalloc(char **pArray, int len)
{
	for (int i=0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("第%d行数据被释放了..\n",i+1);
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
}
void test()
{
	// 读取文件
	FILE *file = fopen("./test.txt", "r");
	if (file == NULL)
	{
		perror("open");
		return;
	}
	// 计算文件行数
	int len = getFileLines(file);
	// 开辟空间
	char **pArray = malloc(sizeof(char *)*len);
	// 将文件中数据放入pArray中
	readFileData(file,pArray,len);
	// 打印数组
	showArray(pArray,len);
	// 释放malloc
	freeMalloc(pArray,len);
	pArray = NULL;
}
int main()
{
	test();
	return 0;
}