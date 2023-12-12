#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[] = {1, 1, 2, 3, 7, 9, 9, 11};

int main()
{
    int arraylen = sizeof(array) / sizeof(int);
    int arrayChange[arraylen];
    int count = 0;
    memset(arrayChange, 0, sizeof(arrayChange));

    arrayChange[0] = array[0];
    int flagNum = 0;

    for(int idx = 0; idx < (arraylen - 1); idx++)
    {
        if(array[idx] != array[idx + 1])
        {
            count += 1;
            arrayChange[count] = array[idx + 1];
        }
    }

    printf("数组为：");
    for(int idx = 0; idx < (count + 1); idx++)
    {
        printf(" %d", arrayChange[idx]);
    }
    printf("\n");

    return 0;
}