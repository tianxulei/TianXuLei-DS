#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* MakeEmpty(struct Node *L)//生成空表
{
    struct Node a;
    a.data=0;
    a.next=NULL;
    L=&a;
    return L;
}
struct Node* FindPrevious(int X,struct Node *L)//找到前驱
{
    struct Node* P=L;
    while(P->next!=NULL && P->next->data!=X)
    {
        P=P->next;
    }
    printf("\n");
    return P;
}
void Insert(int X,struct Node *P)//插入
{
    struct Node* TmpCell;
    TmpCell=malloc(sizeof(struct Node));
    TmpCell->data=X;
    TmpCell->next=P->next;
    P->next=TmpCell;
    printf("已插入:");
    printf("%d\n",X);
}
void IsEmpty(struct Node * L)//判断空表
{
    if(L->next==NULL)
        printf("表为空\n");
    else
        printf("表不为空");
    //return L->next==NULL;
}
int IsLast(struct Node * P)//判断表尾
{
    return P->next==NULL;
}
void Delete(int X,struct Node *L)//删除
{
    struct Node* P;
    struct Node* TmpCell;
    P=FindPrevious(X,L);
    if(!IsLast(P))
    {
        TmpCell=P->next;
        P->next=TmpCell->next;
        free(TmpCell);
    }
    printf("已删除:");
    printf("%d\n",X);
}
void Print(struct Node *L)//打印表
{
    struct Node* P=L->next;
    while(P!=NULL)
    {
        printf("%d\n",P->data);
        P=P->next;
    }
}
struct Node* Find(int X,struct Node* L)//查找
{
    struct Node* P=L->next;
    while(P!=NULL && P->data!=X)
        P=P->next;
    if(P==NULL)
    {
        printf("未找到:");
        printf("%d\n",X);
    }
    else
    {
        printf("已找到:");
        printf("%d\n",X);
    }
    return P;
}
void DeleteList(struct Node* L)//删除表
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
    printf("已删除表");
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
