#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 宏函数
#define ADD(x,y) ((x)+(y)) // 括号里面可以是表达式
/*将频繁短小的函数封装为宏函数,以空间换时间*/
void func()
{
	int a = 0;
	int b = 1;
	printf("a+b=%d\n", ADD(a,b)*20); // 0 + 1 * 20,需要对宏函数进行包装才能达到预期结果
}
/*调用惯例: _cdecl参数传递是从右到左,出栈放是主调函数,名称修饰是_funcname*/
int add(int x, int y)
{
	return x+y; 
}
void b()
{
	int a;  // a在函数b中可以使用
}
void a()
{
	int a;
	b();  // a在函数ab中可以使用
}
void c()
{
	int a = 0x11223344;
	char *p = &a;
	printf("低地址位是:%x\n", *p);  // 44
	printf("高地址位是:%x\n", *(p+3)); // 11
}
int main()
{
	int a;
// 	a();  // a在函数mian a b 中可以使用
// 	func();
	c();
	return 0;
}
	
