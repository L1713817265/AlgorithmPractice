#include <stdio.h>


int nums[] = {7, 14, 9, 2, 3, 11, 1};

int main()
{
    int num1 = 0;
    int num2 = 0;
    int arraylen = sizeof(num2);
    for(int idx = 0; idx < arraylen; idx++)
    {
        for(int idx1 = 0; idx1 < (arraylen - 1); idx++)
        {
            num1 = nums[idx1];
            num2 = nums[idx1 + 1];
            if(num1 > num2)
            {
                nums[idx1] = num2;
                nums[idx1 + 1] = num1;
            }
        }
    }







    return 0;
}