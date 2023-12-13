#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE_NUM 10

int main()
{
    int arraylen = 0;
    int count = 0;
    int count1 = 0;

    printf("请输入数组nums的长度:\n");
    scanf("%d", &arraylen);

    int nums[arraylen];
    memset(nums, 0, arraylen);

    srand(time(NULL));

    printf("生成随机数组为:");
    for (int idx = 0; idx < arraylen; idx++)
    {
        int randomNum = rand() % RANGE_NUM + 1;
        nums[idx] = randomNum;
        printf(" %d", nums[idx]);
    }
    printf("\n");

#if 0
    for(int idx = 0; idx < (arraylen - 1); idx++)
    {
        for(int idx1 = (idx + 1); idx1 < (arraylen - count); idx1++)
        {
            if((nums[idx1] == nums[idx]))
            {
                count++;
                for(int idx2 = idx1; idx2 < (arraylen - count); idx2++)
                {
                    nums[idx2] = nums[idx2 + 1];
                }
            }
        }
    }
#endif

    for(int idx = 0; idx < (arraylen - count1 - 1); idx++)
    {
        int position = idx + 1;
        for(int idx1 = idx + 1; idx1 < (arraylen - count1); idx1++)
        {
            if(nums[idx1] != nums[idx])
            {
                nums[position++] = nums[idx1];
            }
            else
            {
                count++;
            }
        }
        count1 = count;
    }

    printf("数组为：       ");
    for(int idx = 0; idx < (arraylen - count1); idx++)
    {
        printf(" %d", nums[idx]);
    }
    printf("\n");
}