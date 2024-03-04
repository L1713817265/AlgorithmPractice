#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int phraseSelect(char *array, int arrayLen)
{
    int pos = 0;
    int flag = 0;
    for(int idx = 0; idx < arrayLen; idx++)
    {
        if(array[idx] != 32)
        {
            array[pos++] = array[idx];
            flag = 0;
        }
        else if(array[idx] == 32 && flag == 0)
        {
            array[pos++] = array[idx];
            flag++;
        }
    }
    return pos;
}

void phraseRecombine(char *array, int arrayLen)
{
    int count = 0;
    int pos = arrayLen - 2;
    for(int idx = arrayLen - 2; idx > -1; idx--)
    {
        if(array[idx] != 32)
        {
            count++;
        }
        else if(array[idx] == 32 || idx == 0)
        {
            for(int jdx = 0; jdx < count / 2; jdx++)
            {
                char tmp =array[pos + 1 + jdx];
                array[pos + 1 + jdx] = array[pos + count - jdx];
                array[pos + count - jdx] = tmp;
            }
            count = 0;
        }
        pos--;
    }
    for(int idx = 0; idx < (arrayLen - 1) / 2; idx++)
    {
        char tmp1 =array[idx];
        array[idx] = array[arrayLen -2 - idx];
        array[arrayLen -2 - idx] = tmp1;
    }
}

int main()
{
    char ptr[] = "I am      from   China";
    int stringLen = strlen(ptr) + 1;
    printf("%d\n", stringLen);
    
    stringLen = phraseSelect(ptr, stringLen);
    printf("char: %s\n", ptr);
    printf("%d\n", stringLen);

    phraseRecombine(ptr, stringLen);
    printf("char: %s\n", ptr);

    return 0;
}