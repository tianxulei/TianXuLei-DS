#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *P1=head,*P2=head;
    for(int i=0;i<n;++i)
        P1=P1->next;
    if(P1==NULL)
        return head->next;
    while(P1->next!=NULL)
    {
        P1=P1->next;
        P2=P2->next;
    }
    P2->next=P2->next->next;
    return head;
}
int main()
{
    struct ListNode* P=NULL;
    for(int i=1;i<=5;++i)//²åÈëÔªËØ
    {
        struct ListNode* a=malloc(sizeof(struct ListNode));
        a->val=i;
        a->next=P;
        P=a;
    }
    struct ListNode* Q=P;
    printf("input:");
    while(Q)
    {
        printf("%d",Q->val);
        Q=Q->next;
    }
    printf("\n");
    printf("output:");
    P=removeNthFromEnd(P,2);
    while(P)
    {
        printf("%d",P->val);
        P=P->next;
    }
    return 0;
}
