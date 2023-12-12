#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[] = {1, 1, 2, 3, 7, 9, 9, 11};

int main()
{
    int position = 0;

    for(int idx = 1; idx < (sizeof(array) / sizeof(int)); idx++)
    {
        if(array[idx] != array[idx - 1])
        {
            position++;
            array[position] = array[idx];
        }
    }

    printf("数组为：");
    for(int idx = 0; idx < (position + 1); idx++)
    {
        printf(" %d", array[idx]);
    }
    printf("\n");

    return 0;
}