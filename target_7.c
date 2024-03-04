#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR "error"
#define WRONG -1
#define RIGHT 1

char *stringDelete(const char *string)
{
    if(!string)
    {
        return ERROR;
    }
    char *array = (char *)malloc(sizeof(char) * strlen(string));
    int position = 0;
    for(int idx = 0; idx < strlen(string); idx++)
    {
        if(*(string + idx) > 96 && *(string + idx) < 123)
        {
            array[position++] = *(string + idx )- 'a' + 'A';
        }
        else if(*(string + idx) > 64 && *(string + idx) < 91)
        {
            array[position++] = *(string + idx);
        }
    }

    return array;
}

int stringCheck(const char *string)
{
    int len = strlen(string);
    for(int idx = 0; idx < (len / 2); idx++)
    {
        if(*(string + idx) != *(string + len -1 - idx))
        {
            return WRONG;
        }
    }
    return RIGHT;
}

int main()
{
    char *newString = "AS2 dAD  Sa  ";
    printf("%s", newString);
    newString = stringDelete(newString);
    if(stringCheck(newString) == RIGHT)
    {
        printf("是回文串\n");
    }
    else if(stringCheck(newString) == WRONG)
    {
        printf("不是回文串\n");
    }

    return 0;
}