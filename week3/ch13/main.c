#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* P=head;
    if(!head || !head->next)
        return head;

    struct ListNode* t=P->next;
    P->next=P->next->next;
    t->next=P;
    head=t;
    if(!P->next || !P->next->next)
        return head;
    while(P->next->next)
    {
        struct ListNode* m=P->next;
        struct ListNode* n=m->next;
        m->next=n->next;
        P->next=n;
        n->next=m;
        P=P->next;
        if(P->next->next)
            P=P->next;
    }
    return head;
}
struct ListNode* insert(struct ListNode* H,int X)
{
    struct ListNode* a=malloc(sizeof(struct ListNode));
    a->val=X;
    a->next=H;
    H=a;
    return H;
}
int main()
{
    struct ListNode* H=malloc(sizeof(struct ListNode));
    H->val=0;
    H->next=NULL;
    H=insert(H,1);
    H=insert(H,2);
    H=insert(H,3);
    H=insert(H,4);
    printf("input:43210\n");
    H=swapPairs(H);
    printf("output:");
    while(H)
    {
        printf("%d",H->val);
        H=H->next;
    }
    return 0;
}
