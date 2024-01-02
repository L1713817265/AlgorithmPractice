#include <stdio.h>

/* 交换两个整数 */
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}

/* 数组做函数参数会自动弱化成指针 */
int printArray(int *array, int length)
{
    int ret = 0;
    for(int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

/* 时间复杂度 O(n^2) */
void bubbleSort01(int *array, int length)
{
    for(int end = length; end > 0; end--)
    {
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的树 比 前面的数要小 就交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
            }
        }
    }
}

/* 优化1 */
void bubbleSort02(int *array, int length)
{
    int sortedIndex = 0;
    for(int end = length; end > 0; end--)
    {
        /* 已经排好序的索引 */
        sortedIndex = 1;
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的树 比 前面的数要小 就交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 更新排好序的索引 */
                sortedIndex = begin;
            }
        }
        /* 更新 */
        end = sortedIndex;
    }
}

/* 优化2 */
void bubbleSort03(int *array, int length)
{
    int sort = 1;
    for(int end = length; end > 0; end--)
    {
        /* 已经排好序的标志 */
        sort = 1;
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的树 比 前面的数要小 就交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 数据是没有排好序的 */
                sort = 0;
            }
        }
        if(sort == 1)
        {
            break;
        }
    }
}

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65, 23, 54, 12, 73, 128};
    int length = sizeof(array) / sizeof(array[0]);

    bubbleSort03(array, length);
    printArray(array, length);
    return 0;
}