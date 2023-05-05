#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *localVariable();
int main(int args, char *argv[])
{
    /*
        作用域: 变量起作用的范围
        局部变量:在{}范围内定义的变量
        静态局部变量: 在{}范围之内定义的变量,前面加上static修饰变量
        全局变量: 在函数之外定义的变量,作用为整个工程,可以在其他.c文件中声明extern
        静态全局变量: 在函数之外定义的变量,加上static修饰的变量,只能在当前文件使用,无法声明extern
        生命周期: 程序运行至变量定义处开辟空间,所在函数结束后释放空间
    */
    int *p = localVariable();
    printf("p=%d", *p);
    // system("pause");
    return 0;
}
int * localVariable()
{
    int x;
    static int n;  // 静态变量在main函数运行之前开辟空间,再次执行此函数不会再定义
    {
        static int m = 100;
        printf("m=%d\n", m);
    }
    // printf("m=%d\n", m); err m的作用范围是{}内
    // return &x;  不能返回变量x的地址,当前函数执行完毕会释放
    return &n;
}