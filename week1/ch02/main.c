#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* preview;
};
struct Node* MakeEmpty(struct Node *L)//���ɿձ�
{
    struct Node a;
    a.data=0;
    a.preview=NULL;
    struct Node b;
    b.data=0;
    b.next=NULL;
    b.preview=&a;
    a.next=&b;
    L=&a;
    return L;
}
void Insert(int X,struct Node *P)//����
{
    struct Node* TmpCell;
    TmpCell=malloc(sizeof(struct Node));
    TmpCell->data=X;
    TmpCell->preview=P;
    TmpCell->next=P->next;
    P->next->preview=TmpCell;
    P->next=TmpCell;
    printf("�Ѳ���:");
    printf("%d\n",X);
}
void IsEmpty(struct Node * L)//�жϿձ�
{
    if(L->next->next==NULL)
        printf("��Ϊ��\n");
    else
        printf("��Ϊ��\n");
}
int IsLast(struct Node * P)//�жϱ�β
{
    return P->next==NULL;
}
struct Node* Find(int X,struct Node* L)//����
{
    struct Node* P=L->next;
    while(P!=NULL && P->data!=X)
        P=P->next;
    if(P==NULL)
    {
        printf("δ�ҵ�:");
        printf("%d\n",X);
    }
    else
    {
        printf("���ҵ�:");
        printf("%d\n",X);
    }
    return P;
}
void Delete(int X,struct Node *L)//ɾ��
{
    struct Node* P;
    P=Find(X,L);
    if(!IsLast(P))
    {
        P->next->preview=P->preview;
        P->preview->next=P->next;
        free(P);
    }
    printf("��ɾ��:");
    printf("%d\n",X);
}
void Print(struct Node *L)//��ӡ
{
    struct Node* P=L->next;
    while(P->next!=NULL)
    {
        printf("%d\n",P->data);
        P=P->next;
    }
}
void DeleteList(struct Node* L)//ɾ����
{
    struct Node* P=L;
    struct Node* TmpCell;
    while(P!=NULL)
    {
        TmpCell=P->next;
        free(P);
        P=TmpCell;
    }
    L->next=P;
    printf("��ɾ����");
}
int main()
{
    struct Node* L=NULL;
    L=MakeEmpty(L);
    IsEmpty(L);
    for(int i=1;i<=10;++i)
        Insert(i,L);
    IsEmpty(L);
    Delete(5,L);
    Print(L);
    Find(9,L);
    Find(5,L);
    DeleteList(L);
    return 0;
}

