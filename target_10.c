#include <stdio.h>
#include <string.h>
#include "dynamicArrayStack.h"
#include "common.h"

#define false 0
#define true 1

int isValid(char *s) 
{
    if(!s)
    {
        return -1;
    }
    dynamicArrayStack *stack;
    dynamicArrayStackInit(&stack);
    int len = strlen(s);
    int pos = 0;
    if((len % 2) == 1)
    {
        return false;
    }
    while(s[0] == '(' || s[0] == '[' || s[0] == '{')
    {
        if(pos >= (len - 1))
        {
            return true;
        }
        if((s[pos] == '(') && (s[pos + 1] == ')'))
        {
            pos += 2;
        }
        else if((s[pos] == '[') && (s[pos + 1] == ']'))
        {
            pos += 2;
        }
        else if((s[pos] == '{') && (s[pos + 1] == '}'))
        {
            pos += 2;
        }
        else if(s[pos] == '(' || s[pos] == '[' || s[pos] == '{')
        {
            dynamicArrayStackPush(stack, &s[pos]);
            pos++;
        }
        else if(s[pos] == ')' || s[pos] == ']' || s[pos] == '}')
        {
            if(dynamicArrayStackIsEmpty(stack))
            {
                return false;
            }
            char *val = NULL;
            dynamicArrayStackTop(stack, (void **)&val);
            switch(s[pos])
            {
                case ')': 
                    if(*val == '(')
                    {
                        dynamicArrayStackPop(stack);
                        pos++;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']': 
                    if(*val == '[')
                    {
                        dynamicArrayStackPop(stack);
                        pos++;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '}': 
                    if(*val == '{')
                    {
                        dynamicArrayStackPop(stack);
                        pos++;
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }
    }
    dynamicArrayStackDestroy(stack);
    return false;
}

int main()
{
    char *s = "()[[()]](){()}";
    int out = isValid(s);

    printf("%d\n", out);
    return 0;
}