#include <stdio.h>
#include <string.h>
#define STR ""
typedef struct cat
{
	char name[64];
	short age;
}Cat;
typedef struct dog
{
	char a;
	int b;
	char c;
	int d;
}Dog;
int main()
{
	int a = 10;
	Cat c1 = {"hello", 10};
	printf("cat name is %s, age is %d\n", c1.name, c1.age);	
	strcpy(c1.name, "mimo");
	c1.age=3;
	printf("cat name is %s, age is %d\n", c1.name, c1.age);
	printf("--------------------------\n");
	
	Dog d1 = {'a', 10, 'b', 20};
	d1.d = 100;
	Dog *p = &d1;
	printf("%p\n",p);  // p指向字符a的地址
	printf("%p\n",p+1); // 跨过了整个结构体
	p->a = 'x';
	p->b = 33;
	p->c = 'y';
	p->d = 44;
	printf("a=%c b=%d c=%c d=%d\n", p->a,p->b,p->c,p->d);
	/*
	// 使用字符指针操作
	char *q = &d1;
	printf("d=%d\n", *(int*)(q+12));  // 指针占4个字节,p+12跨过3个指针长度指向d需要强转成int类型接收*/
	return 0;
}