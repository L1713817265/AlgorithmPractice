#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 3


int main()
{
    int array[ROW][COLUMN] = {{1, 1, 1}, {2, 2, 2},{3, 3, 3}};

    printf("原数组为：\n");
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int jdx = 0; jdx < ROW; jdx++)
        {
            printf("%d  ", array[idx][jdx]);
        }
        printf("\n");
    }

    for(int idx = 0; idx < ROW; idx++)
    {
        for(int jdx = idx + 1; jdx < ROW; jdx++)
        {
            int tmp = array[idx][jdx];
            array[idx][jdx] = array[jdx][idx];
            array[jdx][idx] = tmp;
        }
    }
    printf("新数组为：\n");
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int jdx = 0; jdx < ROW; jdx++)
        {
            printf("%d  ", array[idx][jdx]);
        }
        printf("\n");
    }
    
    return 0;
}