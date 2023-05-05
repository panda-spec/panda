#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEIGHT 45  // 定义界面高度
#define WIDTH 60  // 定义界面宽度

/*定义坐标*/
typedef struct _xy
{
    int x;
    int y;
}COOR;
/*定义蛇*/
typedef struct _snake
{
    COOR arr[HEIGHT*WIDTH];
    COOR food;
    int size;
}SNAKE;
/*随机生成食物*/
void init_food(SNAKE *snake)
{
    // 设置随机数种子
    srand(time(NULL));

    snake->food.y = rand() % HEIGHT + 1;
    snake->food.x = rand() % WIDTH + 1;
}
// 初始化蛇
void init_snake(SNAKE *snk)
{
    // 蛇头位置初始化
    snk->arr[0].x = WIDTH / 2;
    snk->arr[0].y = HEIGHT / 2;
    // 蛇尾位置初始化
    snk->arr[1].x = WIDTH / 2 - 1;
    snk->arr[1].y = HEIGHT / 2;
    // 初始化身体大小
    snk->size = 3;
    // 食物位置初始化
    init_food(snk);
}
/*UI*/
void show_UI(SNAKE *snake)
{
    for (int i=0; i < snake->size; i++)
    {
        if (i == 0)
        {
            printf(">");
        }
        else
        {
            printf("-");
        }
    }
}
int main()
{
    SNAKE *snake = (SNAKE *)malloc(sizeof(SNAKE));
    init_snake(snake);
    return 0;
}