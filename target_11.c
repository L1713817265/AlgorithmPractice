#include <stdio.h>
#include <string.h>
#include "LinkList.h"

int printStruct(void *arg)
{
    int val = *(int *)arg;
    printf("%d\t", val);
}

LinkList *mergeTwoLists(LinkList *list1, LinkList *list2)
{
    if(!list1 || !list2)
    {
        return 0;
    }
    int size1 = 0;
    LinkListGetLength(list1, &size1);
    int size2 = 0;
    LinkListGetLength(list2, &size2);

    if((size1 < 0) || (size2 < 0))
    {
        return 0;
    }

    LinkList *list = NULL;
    LinkListInit(&list);

    LinkNode *travelNode1 = list1->head->next;
    LinkNode *travelNode2 = list2->head->next;

    int val = 0;
    while(travelNode1 || travelNode2)
    {
        if(travelNode1 && travelNode2)
        {
            int val1 = *(int *)travelNode1->data;
            int val2 = *(int *)travelNode2->data;
            if(val1 < val2)
            {
                LinkListTailInsert(list, travelNode1->data);
                travelNode1 = travelNode1->next;
            }
            else
            {
                LinkListTailInsert(list, travelNode2->data);
                travelNode2 = travelNode2->next;
            }
        }
        else if(travelNode1 && !travelNode2)
        {
            LinkListTailInsert(list, travelNode1->data);
            travelNode1 = travelNode1->next;
        }
        else if(!travelNode1 && travelNode2)
        {
            LinkListTailInsert(list, travelNode2->data);
            travelNode2 = travelNode2->next;
        }
    }
    return list;
}

int main()
{
    int l1[] = {1, 2, 4};
    int l2[] = {1, 3, 4};

    int len1 = sizeof(l1) / sizeof(l1[0]);
    int len2 = sizeof(l2) / sizeof(l2[0]);

    LinkList *list1 = NULL;
    LinkListInit(&list1);

    LinkList *list2 = NULL;
    LinkListInit(&list2);

    for(int idx = 0; idx < len1; idx++)
    {
        LinkListTailInsert(list1, (void *)&l1[idx]);
    }
    for(int idx = 0; idx < len2; idx++)
    {
        LinkListTailInsert(list2, (void *)&l2[idx]);
    }
    
    LinkListForeach(list1, printStruct);
    printf("\n");
    LinkListForeach(list2, printStruct);
    printf("\n");
    
    LinkList *list = mergeTwoLists(list1, list2);
    LinkListForeach(list, printStruct);
    printf("\n");

    return 0;
}