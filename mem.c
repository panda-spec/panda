#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if 0
/*
	代码区：共享,只读
	数据区：全局变量,常量,静态变量(已初始化data,未初始化bss)
	栈区：先进后出,编译器自动分配和释放
	堆区：由程序分配释放
*/
int *func()
{
	static int a = 10;
	return &a;
}
char *str()
{
	char *p = "hello";
	return p;
}
// 不要返回局部变量地址,栈区在函数执行完成后会释放,可以将地址指向堆区或者常量区
int main()
{
	int *p = func();
	*p = *p + 1;
	int *q = func();
	printf("%d\n",*q);
	
	char *k = str();
	printf("%s\n", k);
	return 0;
}
#endif
int *getnum()
{
	int *p = (int *)malloc(sizeof(int));
	for (int i=0; i < 5; i++)
	{
		p[i] = 100 + i;
	}
	return p;
}
void test()
{
	int *p = getnum();
	for (int i=0; i < 5; i++)
	{
		printf("%d\t", p[i]);
	}
	free(p);
	p = NULL;
}
// 同级指针取到的只是指针里面的内容,如果要修改内容,需要使用高级指针操作地址
void mallocSpace(char **p) 
{
	char *temp = (char *)malloc(128);
	memset(temp,0,100);
	strcpy(temp, "hello c");
	*p = temp;
}
void test1()
{
	char *p = NULL;
	mallocSpace(p);
	printf("%s\n", p);
}
int main()
{
// 	char *p = "2";
// 	printf("%d\n", *p);
// 	test();
	test1();
	return 0; 
}