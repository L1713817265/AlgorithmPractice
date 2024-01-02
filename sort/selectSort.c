#include <stdio.h>

/* 选择排序: 相较于冒泡排序, 减少了交换的次数 */
/* 时间复杂度也是O(n^2) */

int printArray(int *array, int length)
{
    int ret = 0;
    for(int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

/* 选择排序 */
int selectSort(int *array, int length)
{
    int ret = 0;
    if(!array)
    {
        return;
    }
    int minValue = 0;
    int minIndex = 0;
    for(int pos = 0; pos < length; pos++)
    {
        minValue = array[pos];
        for(int begin = pos + 1; begin < length; begin++)
        {
            /* 遍历到的元素比最小值要小, 就更新最小值 */
            if(minValue > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }
        }

        if(array[pos] > minValue)
        {
            int temp = array[pos];
            array[pos] = minValue;
            array[minIndex] = temp;
        }
    }
    return ret;
}

int main()
{
    int array[] = {1, 30, 24, 5, 58, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);
    
    selectSort(array, length);
    printArray(array, length);
    return 0;
}