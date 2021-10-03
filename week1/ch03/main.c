#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int next;
};
struct Node CursorSpace[15];
void MakeEmpty(struct Node a[],int SpaceSize)//初始化数组
{
    for(int i=0;i<SpaceSize-1;++i)
    {
         a[i].next=i+1;
         a[i].data=0;
    }
    a[SpaceSize-1].next=0;
}
void MakeEmpty1(struct Node a[],int L)//建空表
{
    a[L].next=0;
}
int CursorAlloc()//申请空间
{
    int P;
    P=CursorSpace[0].next;
    CursorSpace[0].next=CursorSpace[P].next;
    return P;
}
void CursorFree(int P)//释放空间
{
    CursorSpace[P].next=CursorSpace[0].next;
    CursorSpace[0].next=P;
}
int IsEmpty(int L)//判断空表
{
    return CursorSpace[L].next==0;
}
int IsLast(int X,int L)//判断尾
{
    return CursorSpace[X].next==0;
}
int Find(int X,int L)//找元素
{
    int P;
    P=CursorSpace[L].next;
    while(P && CursorSpace[P].data!=X)
        P=CursorSpace[P].next;
    return P;
}
int FindPrevious(int X,int L)//找前驱
{
    int P=CursorSpace[L].next;
    while(CursorSpace[CursorSpace[P].next].data!=X && P!=0)
        P=CursorSpace[P].next;
    return P;
}
void Delete(int X,int L)//删除
{
    int P,TmpCell;
    P=FindPrevious(X,L);
    if(!IsLast(P,L))
    {
        TmpCell=CursorSpace[P].next;
        CursorSpace[P].next=CursorSpace[TmpCell].next;
        CursorFree(TmpCell);
    }
    printf("成功删除");
    printf("%d\n",X);
}
void Insert(int X,int L,int P)//插入
{
    int TmpCell;
    TmpCell=CursorAlloc();
    CursorSpace[TmpCell].data=X;
    CursorSpace[TmpCell].next=CursorSpace[P].next;
    CursorSpace[P].next=TmpCell;
    printf("成功插入");
    printf("%d\n",X);
}
void Print(struct Node a[],int SpaceSize)//输出全部数组
{
    for(int i=0;i<SpaceSize;++i)
    {
        printf("%d %d %d\n",i,a[i].data,a[i].next);
    }
}
void Print1(int L)//打印表L
{
    int P=CursorSpace[L].next;
    while(CursorSpace[P].next!=0)
    {
        printf("%d\n",CursorSpace[P].data);
        P=CursorSpace[P].next;
    }
    printf("%d\n",CursorSpace[P].data);
}
int main()
{
    MakeEmpty(CursorSpace,15);
    int L=5;
    MakeEmpty1(CursorSpace,L);

    printf("打印数组\n");
    Print(CursorSpace,15);
    Insert(1,L,L);
    Insert(2,L,L);
    Insert(4,L,L);
    Insert(5,L,L);
    Delete(2,L);
    printf("打印数组\n");
    Print(CursorSpace,15);
    printf("打印表L\n");
    Print1(L);

    return 0;
}
