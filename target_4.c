#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE_NUM 10

int main()
{
    int arraylen = 0;
    int val = 0;
    int position = 0;

    printf("请输入val值:\n");
    scanf("%d", &val);
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

    printf("数组为：       ");
    for(int idx = 0; idx < arraylen; idx++)
    {
        if(nums[idx] != val)
        {
            nums[position++] = nums[idx];
            printf(" %d", nums[idx]);
        }
    }
    printf("\n");
}
