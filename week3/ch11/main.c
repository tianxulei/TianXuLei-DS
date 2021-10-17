#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(!l1 && !l2)
        return NULL;
    if(!l1 && l2)
        return l2;
    if(l1 && !l2)
        return l1;
    struct ListNode* P=l1;
    while(l2)
    {
        if(l1->val > l2->val)//插入l1最前面
        {
            struct ListNode* t=malloc(sizeof(struct ListNode));
            t=l2;
            l2=l2->next;
            t->next=P;
            P=t;
            l1=P;
        }
        else if(P->next)
        {
            if(P->next->val > l2->val)
            {
                struct ListNode* t=P->next;
                P->next=l2;
                l2=l2->next;
                P=P->next;
                P->next=t;
            }
            else if(P->next->val <= l2->val)
            {
                if(P->next->next)
                    P=P->next;
                else
                {
                    P->next->next=l2;
                    return l1;
                }
            }
        }
        else
        {
            P->next=l2;
            return l1;
        }
    }
    return l1;
}
int main()
{
    struct ListNode* l1=NULL;
    printf("input:");
    for(int i=2;i<=5;++i)
        printf("%d ",i);
    printf("\n");

    for(int i=5;i>=2;--i)//插入元素
    {
        struct ListNode* a=malloc(sizeof(struct ListNode));
        a->val=i;
        a->next=l1;
        l1=a;
    }
    struct ListNode* l2=NULL;
    printf("input:");
    for(int i=2;i<=7;++i)
        printf("%d ",i);
    printf("\n");

    for(int i=7;i>=3;--i)//插入元素
    {
        struct ListNode* a=malloc(sizeof(struct ListNode));
        a->val=i;
        a->next=l2;
        l2=a;
    }
    printf("output:");
    l1=mergeTwoLists(l1,l2);
    while(l1)
    {
        printf("%d ",l1->val);
        l1=l1->next;
    }
    return 0;
}
