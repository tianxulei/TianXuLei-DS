#include <stdio.h>
#include <stdlib.h>
struct QueueRecord
{
    int Capacity;
    int Front;//��β
    int Rear;//����
    int Size;
    int Array[100];
};
typedef struct QueueRecord* Queue;
int IsEmpty(Queue Q)//�жϿն���
{
    return Q->Size==0;
}
int IsFull(Queue Q)//�ж�������
{
    if(Q->Rear+1==Q->Front && Q->Size!=0)
        return 1;
    else
        return 0;
}
Queue MakeEmpty(Queue Q)//�����ն���
{
    Queue P=Q;
    P->Size=0;
    P->Front=1;
    P->Rear=0;
    return P;
}
int Succ(int Value,Queue Q)//��������ѭ��
{
    if(++Value==Q->Capacity)
        Value=0;
    return Value;
}
void Enqueue(int X,Queue Q)//���
{
    if(IsFull(Q))
        printf("��������\n");
    else
    {
        printf("����δ��\n");
        Q->Size++;
        Q->Rear=Succ(Q->Rear,Q);
        Q->Array[Q->Rear]=X;
        printf("�Ѳ���");
        printf("%d\n",X);
    }
}
int Outqueue(Queue Q)//����
{
    int X=0;
    if(IsEmpty(Q))
        printf("����Ϊ��\n");
    else
    {
        Q->Size--;
        X=Q->Array[Q->Front];
        Q->Front=Succ(Q->Front,Q);
        printf("��ȡ��");
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
