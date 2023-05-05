#include <stdio.h>
#include <stdlib.h>
// #include "func1.c" // 导入其他.c文件
#include "zero.h"
static int a = 10; // 静态全局变量
// int func1();
void func()
{
	static int b = 0; // 静态局部变量
	extern int c;  // 声明其他.c文件中的静态全局变量无法获得值,只在当前.c文件中使用
// 	extern int d;
	printf("d=%d\n", d);
	printf("c=%c\n", c);
	int k = func1();
	printf("k=%d\n", k);
}
/*静态变量在运行前分配内存,生命周期是整个程序运行期间,只能内部链接使用*/
/*c语言全局变量前默认加了关键字 extern 可以外部链接使用*/

const short l = 10;  // 全局const常量,放在常量区中,受到常量区保护
void func2()
{
// 	l = 1;
// 	printf("l=%d\n", l); 直接赋值无法修改
// 	short *p = &l;
// 	*p = 10;
// 	printf("l=%d\n", l); 通过常量地址也无法修改内容
}
void func3()
{
	const short a = 0;  // 在局部声明的常量是伪常量,数据存放在栈区
// 	short *p = &a;
// 	*p = 10;
// 	printf("a=%d\n", a);  依然无法修改,不知道是不是版本问题
	int arr[l];  // 全局常量是真正的常量,可以将变量用来定义数组元素个数
// 	int arrq[a]; 伪常量无法用来定义数组元素个数
	for (int i=0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%p\n", arr+i);
		printf("hello\n");
	}
}
// 常量区内容共享内存地址,有些编译器可以修改,主流编译器都无法更改常量
void func4()
{
	char *p1 = "hello world";  // 字符串常量
	char *p2 = "hello world";
	printf("p1=%p\n", p1);
	printf("p2=%p\n", p2);  // 打印的地址相同,指向的是同一个内存地址
	printf("hello world:%p\n", &"hello world");  // 直接打印字符串常量地址
}
int main()
{
// 	func();
// 	func2();
// 	func3();
	func4();
	return 0;
}