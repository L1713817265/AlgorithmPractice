# include <stdio.h>

int printArray(int *array, int length)
{
    int ret = 0;
    for(int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

void quickSort01(int *array, int start, int end)
{
    if(!array)
    {
        return;
    }
    /* 递归 必须考虑结束条件 */
    if (start >= end)
    {
        return;
    }
    int temp = array[start];
    int left = start;
    int right = end;
    while (start < end)
    {
        while(start < end)
        {
            if(array[end] < temp)
            {
                array[start++] = array[end];
                break;
            }
            else
            {
                end--;
            }
        }
        while(start < end)
        {
            if(array[start] > temp)
            {
                array[end--] = array[start];
                break;
            }
            else
            {
                start++;
            }
        }
    }
    array[start] = temp;
    quickSort01(array, left, start);
    quickSort01(array, start + 1, right);
}

/* 找到基准值的位置 */
static int findBaseValPos(int *array, int start, int end)
{
    int ret = 0;
    if(!array)
    {
        return;
    }
    end--;

    /* 基准值 */
    int baseValPos = array[start];
    while(start < end)
    {
        while(start < end)
        {
            if(array[end] < baseValPos)
            {
                array[start++] = array[end];
                break;
            }
            else
            {
                end--;
            }
        }
        
        while(start < end)
        {
            if(array[start] > baseValPos)
            {
                array[end--] = array[start];
                break;
            }
            else
            {
                start++;
            }
        }
    }
    array[start] = baseValPos;

    return start;
}

int quickSort02(int *array, int start, int end)
{
    int ret = 0;
    if(!array)
    {
        return;
    }
    if(start >= end)
    {
        return ret;
    }
    int baseValPos = findBaseValPos(array, start, end);

    /* 对基准值左侧排序 */
    quickSort02(array, start, baseValPos);
    /* 对基准值右侧排序 */
    quickSort02(array, baseValPos + 1, end);
}

int main()
{
    int array[] = {1, 30, 24, 5, 58, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);
    
    quickSort02(array, 0, length);
    printArray(array, length);
    return 0;
}