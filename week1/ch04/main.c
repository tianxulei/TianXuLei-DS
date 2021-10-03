#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
int IsEmpty(struct Node* S)//判断空栈
{
    return S->next==NULL;
}
int Pop(struct Node* S)//取出
{
    int X=0;
    struct Node* P;
    if(!IsEmpty(S))
    {
        X=S->next->data;
        P=S->next;
        S->next=S->next->next;
        free(P);
        printf("成功取出");
        printf("%d\n",X);
    }

    else
        printf("栈已空");
    return X;
}
void MakeEmpty(struct Node* S)//清空栈
{
    if(S==NULL)
        printf("栈已空");
    else
        while(!IsEmpty(S))
             Pop(S);
        printf("已清空栈");
}
struct Node* CreatStack()//创建空栈
{
    struct Node* P;
    P=malloc(sizeof(struct Node));
    P->next=NULL;
    P->data=0;
    printf("创建成功\n");
    return P;
}
void Push(int X,struct Node* S)//加入
{
    struct Node* TmpCell;
    TmpCell=malloc(sizeof(struct Node));
    TmpCell->data=X;
    TmpCell->next=S->next;
    S->next=TmpCell;
    printf("成功放入");
    printf("%d\n",X);
}
int Top(struct Node* S)//返回栈顶
{
    if(!IsEmpty(S))
        return S->next->data;
    return 0;
}
int main()
{
    struct Node* S=NULL;
    printf("创建空栈\n");
    S=CreatStack();
    for(int i=1;i<=5;++i)
        Push(i,S);
    Pop(S);
    Pop(S);
    MakeEmpty(S);
    Pop(S);
    return 0;
}
