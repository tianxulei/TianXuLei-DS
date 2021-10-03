#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
int IsEmpty(struct Node* S)//�жϿ�ջ
{
    return S->next==NULL;
}
int Pop(struct Node* S)//ȡ��
{
    int X=0;
    struct Node* P;
    if(!IsEmpty(S))
    {
        X=S->next->data;
        P=S->next;
        S->next=S->next->next;
        free(P);
        printf("�ɹ�ȡ��");
        printf("%d\n",X);
    }

    else
        printf("ջ�ѿ�");
    return X;
}
void MakeEmpty(struct Node* S)//���ջ
{
    if(S==NULL)
        printf("ջ�ѿ�");
    else
        while(!IsEmpty(S))
             Pop(S);
        printf("�����ջ");
}
struct Node* CreatStack()//������ջ
{
    struct Node* P;
    P=malloc(sizeof(struct Node));
    P->next=NULL;
    P->data=0;
    printf("�����ɹ�\n");
    return P;
}
void Push(int X,struct Node* S)//����
{
    struct Node* TmpCell;
    TmpCell=malloc(sizeof(struct Node));
    TmpCell->data=X;
    TmpCell->next=S->next;
    S->next=TmpCell;
    printf("�ɹ�����");
    printf("%d\n",X);
}
int Top(struct Node* S)//����ջ��
{
    if(!IsEmpty(S))
        return S->next->data;
    return 0;
}
int main()
{
    struct Node* S=NULL;
    printf("������ջ\n");
    S=CreatStack();
    for(int i=1;i<=5;++i)
        Push(i,S);
    Pop(S);
    Pop(S);
    MakeEmpty(S);
    Pop(S);
    return 0;
}
