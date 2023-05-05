#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int second,minute,hour;
    second = 0;
    minute = 0;
    hour = 0;
    while (true)
    {
        sleep(1);
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }
        printf("%02d:%02d:%02d\n", hour, minute, second);
    }
}