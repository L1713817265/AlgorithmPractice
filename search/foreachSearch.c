#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 宏定义在预处理阶段 被替换 */
#define BUFFER_SIZE 10

/* 宏函数 -> 无法调试 */
// #define CHECK_PTR()

int printArray(int *array, int length)
{
    int ret = 0;
    if(!array)
    {
        return 0;
    }
    for(int idx = 0; idx < length; idx++)
    {
        printf("buffer[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int findAppointValPos(int *array, int length, int val, int *pPos)
{
    int ret = 0;
    int flag = 0;
    if(!array)
    {
        return 0;
    }
    for(int idx = 0; idx < length; idx++)
    {
        if(array[idx] == val)
        {
            *pPos = idx;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        *pPos = -1;
    }
    
    return ret;
}

int main()
{
    /* 随机数种子 */
    srand(time(NULL));

    int buffer[BUFFER_SIZE] = {0};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 10 + 1;
    }
    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);
    int pos = 0;
    findAppointValPos(buffer, length, 4, &pos);
    printf("%d\n", pos);
    return 0;
}
