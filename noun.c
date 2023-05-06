#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*位运算*/
void test1()
{
	// 按位取反,对符号也会取反
	int a = 2;
	int b = ~a;
	printf("b=%d\n", b); // -3
	
	// 按位与,同1得1,&
	int c = 6;
	int d = 9;
	printf("c & d = %d\n", c & d); // 0 
	
	// 按位或 | 同0得0,有1得1
	int x = 12;
	int y = -3;
	printf("x | y = %d\n", x | y);
	
	// 按位异或 相同为假,相反为真
	int j = 6;
	int k = 9;
	
	// 交换j k 数据
	j = j ^ k;
	k = j ^ k;
	j = j ^ k;
	printf("j=%d k = %d\n", j,k);
}
/*位移运算符*/
void test2()
{
	// 左移,*2的n次方
	int num1 = 20;
	printf("num1=%d\n", num1 << 3);
	// 右移,/2的n次方. 有些系统在符号位用0填充有些用1填充
	int num2 = 10;
	printf("num2=%d\n", num2 >> 3);
}
int main()
{
// 	test1();
	test2();
	return 0;
}