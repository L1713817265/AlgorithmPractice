#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE_NUM 10

int main()
{
    int target = 0;
    int arraylen = 0;
    int count = 0;

    printf("请输入target值:\n");
    scanf("%d", &target);
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

    if(arraylen < 2)
    {
        printf("数组长度小于2,无法找出两个数相加得到target值。\n");
    }
    else
    {
        for(int idx = 0; idx < (arraylen - 1); idx++)
        {
            for(int idx1 = (idx + 1); idx1 < arraylen; idx1++)
            {
                int sum = array[idx] + array[idx1];
                if(sum == target)
                {
                    printf("数组中索引为%d和%d的元素和为target值。\n", idx, idx1);
                    count += 1;
                }
            }
        }
    }

    if(count < 1)
    {
        printf("找不到合为target值的两个元素");
    }

    return 0;
}