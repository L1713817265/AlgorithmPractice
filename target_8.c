#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 7

void maxProfit(const int *array, int arrayLen)
{
    int count = 0;
    int max = 0;
    int min = 0;
    for(int idx = 0; idx < arrayLen; idx++)
    {
        for(int idx1 = idx + 1; idx1 < arrayLen; idx1++)
        {
            if((array[idx] < array[idx1]) && (array[idx1] - array[idx] > count))
            {
                count = array[idx1] - array[idx];
                max = idx1;
                min = idx;
            }
        }
    }
    printf("在第%d日买入并在第%d日卖出可获取最大收益%d\n", max + 1, min + 1, count);
}

int main()
{
    int array[BUFFER_SIZE] = {7, 1, 4, 2, 5, 6, 3};
    int arrayLen = sizeof(array) / sizeof(int);
    maxProfit(array, arrayLen);
    return 0;
}