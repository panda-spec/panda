#include <stdio.h>
#include <stdlib.h>

union x
{
    short b;
    char buf[2];
};
int main()
{
    union x tmp;
    tmp.b = 0x0102;
    if (tmp.buf[0] == 0x01)
    {
        printf("大端\n");
    }
    else
    {
        printf("小端\n");
    }
}
