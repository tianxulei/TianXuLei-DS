#include <stdio.h>
#include <stdlib.h>
struct QueueRecord
{
    int Capacity;
    int Front;//队尾
    int Rear;//队首
    int Size;
    int Array[100];
};
typedef struct QueueRecord* Queue;
int IsEmpty(Queue Q)//判断空队伍
{
    return Q->Size==0;
}
int IsFull(Queue Q)//判断满队伍
{
    if(Q->Rear+1==Q->Front && Q->Size!=0)
        return 1;
    else
        return 0;
}
Queue MakeEmpty(Queue Q)//创建空队伍
{
    Queue P=Q;
    P->Size=0;
    P->Front=1;
    P->Rear=0;
    return P;
}
int Succ(int Value,Queue Q)//进行数组循环
{
    if(++Value==Q->Capacity)
        Value=0;
    return Value;
}
void Enqueue(int X,Queue Q)//入队
{
    if(IsFull(Q))
        printf("队列满了\n");
    else
    {
        printf("队列未满\n");
        Q->Size++;
        Q->Rear=Succ(Q->Rear,Q);
        Q->Array[Q->Rear]=X;
        printf("已插入");
        printf("%d\n",X);
    }
}
int Outqueue(Queue Q)//出队
{
    int X=0;
    if(IsEmpty(Q))
        printf("队伍为空\n");
    else
    {
        Q->Size--;
        X=Q->Array[Q->Front];
        Q->Front=Succ(Q->Front,Q);
        printf("已取出");
        printf("%d\n",X);
    }
    return X;
}
int main()
{
    Queue Q=NULL;
    Q=malloc(sizeof(struct QueueRecord));
    Q=MakeEmpty(Q);
    Enqueue(5,Q);
    Enqueue(6,Q);
    Enqueue(7,Q);
    Enqueue(8,Q);
    Outqueue(Q);
    return 0;
}
