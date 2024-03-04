#include <stdio.h>

int printArray(int *array, int length)
{
    int ret = 0;
    if(!array)
    {
        return 0;
    }
    for(int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int insertSort(int *array, int length)
{
    if(!array)
    {
        return;
    }
    int ret = 0;
    int temp = 0;
    int cur = 0;
    for(int idx = 1; idx < length; idx++)
    {
        cur = idx;
        temp = array[idx];
        while(cur > 0 && array[cur - 1] > temp)
        {
            array[cur] = array[cur - 1];
            cur--;
        }
        array[cur] = temp;
    }
    return ret;
}

int main()
{
    int array[] = {1, 30, 24, 5, 58, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);
    
    insertSort(array, length);
    printArray(array, length);
    return 0;
}