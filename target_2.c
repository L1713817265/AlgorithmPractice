#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE_NUM 10

void quick_sort(int *array, int firstTmp, int len);

int main()
{
    int arraylen = 0;

    printf("请输入数组长度:\n");
    scanf("%d", &arraylen);

    int array[arraylen];
    memset(array, 0, arraylen);

    srand(time(NULL));
        
    printf("生成随机数组为:");
    for (int idx = 0; idx < arraylen; idx++)
    {
        int randomNum = rand() % RANGE_NUM + 1;
        array[idx] = randomNum;
        printf(" %d", array[idx]);
    }
    printf("\n");

    quick_sort(array, 0, arraylen);

    printf("排序后数组为:");
    for (int idx = 0; idx < arraylen; idx++)
    {
        printf(" %d", array[idx]);
    }
    printf("\n");

    return 0;
}
    
void quick_sort(int *array, int firstTmp, int len)
{
    if(len < 2)
    {
        return;
    }
    int first = firstTmp;
    int last = len - 1;
    int key = array[first];
    while(first < last)
    {
        while((first < last) && (array[last] >= key))
        {
            --last;
        }
        array[first] = array[last];

        while((first < last) && (array[first] < key))
        {
            ++first;
        }
        array[last] = array[first];
    }
    array[first] = key;

    quick_sort(array, firstTmp, first);
    quick_sort(array, (first + 1), len);

    return;
}