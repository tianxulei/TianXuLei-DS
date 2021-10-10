#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode * Insert(int X,struct ListNode* L)
{
    if(L==NULL)
    {
        L=malloc(sizeof(struct ListNode));
        L->val=X;
        L->next=NULL;
        return L;
    }
    else
    {
        struct ListNode *TmpCell;
        TmpCell=malloc(sizeof(struct ListNode));
        TmpCell->val=X;
        TmpCell->next=L;
        L=TmpCell;
        return L;
    }
}
void Print(struct ListNode *L)
{
    while(L!=NULL)
    {
        printf("%d",L->val);
        L=L->next;
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int a=0,b=0;
    struct ListNode *l4=NULL,*l3;
    struct ListNode* TmpCell;
    b=l1->val+l2->val+a;
    if(b>9)
    {
        a=1;b=b%10;
    }
    else
        a=0;
    TmpCell=malloc(sizeof(struct ListNode));
    TmpCell->val=b;
    TmpCell->next=NULL;
    l4=TmpCell;l3=l4;
    l1=l1->next;
    l2=l2->next;
    while(l1 || l2)
    {
        if(l1 && l2)
        {
            b=l1->val+l2->val+a;
            if(b>9)
            {
                a=1;b=b%10;
            }
            else
                a=0;
            struct ListNode* TmpCell;
            TmpCell=malloc(sizeof(struct ListNode));
            TmpCell->val=b;
            TmpCell->next=NULL;
            l3->next=TmpCell;
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        else if(!l1 && l2)
        {

            b=l2->val+a;
            if(b>9)
            {
                a=1;b=b%10;
            }
            else
                a=0;
            struct ListNode* TmpCell;
            TmpCell=malloc(sizeof(struct ListNode));
            TmpCell->val=b;
            TmpCell->next=NULL;
            l3->next=TmpCell;
            l3=l3->next;
            l2=l2->next;
        }
        else if(l1 && !l2)
        {

            b=l1->val+a;
            if(b>9)
            {
                a=1;b=b%10;
            }
            else
                a=0;
            struct ListNode* TmpCell;
            TmpCell=malloc(sizeof(struct ListNode));
            TmpCell->val=b;
            TmpCell->next=NULL;
            l3->next=TmpCell;
            l3=l3->next;
            l1=l1->next;
        }
    }
    if(a==1)
    {
        struct ListNode* TmpCell;
        TmpCell=malloc(sizeof(struct ListNode));
        TmpCell->val=a;
        TmpCell->next=NULL;
        l3->next=TmpCell;
        l3=l3->next;
    }
    return l4;
}
int main()
{
    struct ListNode *l1,*l2,*L;
    l1=l2=L=NULL;
    l1=Insert(9,l1);l1=Insert(9,l1);l1=Insert(9,l1);l1=Insert(9,l1);l1=Insert(9,l1);l1=Insert(9,l1);l1=Insert(9,l1);
    l2=Insert(9,l2);l2=Insert(9,l2);l2=Insert(9,l2);l2=Insert(9,l2);
    printf("input:");Print(l1);printf("\n");
    printf("input:");Print(l2);printf("\n");
    L=addTwoNumbers(l1,l2);
    printf("output:");
    Print(L);
    return 0;
}
