#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_NUM 10

int main()
{
    int target = 0;
    int arraylen = 0;
    int array[] = {0};
    int idx, idx1;
    int count = 0;
    int sum = 0;
    int randomNum = 0;

    printf("请输入target值:\n");
    scanf("%d", &target);
    printf("请输入数组长度:\n");
    scanf("%d", &arraylen);

    srand(time(NULL));
    
    for (idx = 0; idx < arraylen; idx++)
    {
        randomNum = rand() % RANGE_NUM + 1;
        array[idx] = randomNum;
    }

    if(arraylen < 2)
    {
        printf("数组长度小于2,无法找出两个数相加得到target值。\n");
    }
    else
    {
        printf("数组为：");
        for (idx = 0; idx < arraylen ; idx++)
        {
            printf("%d ", array[idx]);
        }
        printf("\n");
        
        for(idx = 0; idx < (arraylen - 1); idx++)
        {
            for(idx1 = (idx + 1); idx1 < arraylen; idx1++)
            {
                sum = array[idx] + array[idx1];
                if(sum == target)
                {
                    printf("数组中索引为%d和%d的元素和为target值。\n", idx, idx1);
                    count += 1;
                }
            }
        }
    }
    if(count == 0)
    {
        printf("找不到合为target值的两个元素");
    }
    return 0;
}