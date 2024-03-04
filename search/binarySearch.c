#include <stdio.h>


/* 返回值: 1表示存在 0表示不存在*/
int binarySearchAppointValPos(int *array, int length, int val)
{
    if(!array)
    {
        return 0;
    }
    int start = 0;
    int end = length - 1;
    int mid = 0;
    while(start <= end)
    {
        mid = (end + start) >> 1;
        if(array[mid] == val)
        {
            return mid;
        }
        else if(array[mid] < val)
        {
            start = mid + 1;
        }
        else if(array[mid] > val)
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {11, 24, 36, 107, 298, 400};
    int length = sizeof(array) / sizeof(array[0]);

    int out = binarySearchAppointValPos(array, length, 107);
    printf("out: %d\n", out);
    return 0;
}