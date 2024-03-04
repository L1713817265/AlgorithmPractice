#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

//  数组作为函数的返回值

int *mergeOrderNums(int *num1, int num1size, int *num2, int num2size, int *newNumSize)
{
    int arratLen = num1size + num2size;
    int *newArray = malloc(sizeof(int) * arratLen);
    // 必须是== 不能是= =是赋值操作
    if(!newArray)
    {
        return NULL;
    }

    int idx1 = 0;
    int idx2 = 0;
    int pos = 0;
    while(idx1 < num1size && idx2 < num2size)
    {
        if(num1[idx1] < num2[idx2])
        {
            newArray[pos] = num1[idx1++];
        }
        else
        {
            newArray[pos] = num2[idx2++];
        }
        pos++;
    }

    if(idx1 == num1size)
    {
        // num1 循环结束
        for(int idx = idx2; idx < num2size; idx++)
        {
            newArray[pos++] = num2[idx2++];
        }
    }
    else if(idx2 == num1size)
    {
        // num2 循环结束
        for(int idx = idx1; idx < num1size; idx++)
        {
            newArray[pos++] = num2[idx1++];
        }
    }
    *newNumSize = arratLen;
    return newArray;
}

int main()
{
    int num1[] = {1, 1, 2, 3, 3, 5, 7, 19};
    int num2[] = {2, 7, 9, 12, 17};
    int num1size = sizeof(num1) / sizeof(int);
    int num2size = sizeof(num2) / sizeof(int);
    int newSize = 0;
    int *newArray = mergeOrderNums(num1, num1size, num2, num2size, &newSize);
    for(int idx = 0; idx < newSize; idx++)
    {
        printf("newArray[%d] = %d\n", idx, *(newArray + idx));
    }

    return 0;
} 