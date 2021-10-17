#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int MaxElements);//做初始队列
void Destory(PriorityQueue H);//删除队列
void MakeEmpty(PriorityQueue H);//清空队列
void Insert(ElementType X,PriorityQueue H);//插入元素
ElementType DeleteMin(PriorityQueue H);//删除最小元
ElementType FindMin(PriorityQueue H);//返回最小元
int IsEmpty(PriorityQueue H);//判断是否为空
int IsFull(PriorityQueue H);//判断是否为满

#endif // HEAD_H_INCLUDED

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    if(MaxElements<10)
        printf("Priority queue size is too small");
    H=malloc(sizeof(struct HeapStruct));
    if(H==NULL)
        printf("Out of space!!!");
    H->Elements=malloc((MaxElements+1)*sizeof(ElementType));
    if(H->Elements==NULL)
        printf("Out of space!!!");
    H->Capacity=MaxElements;
    H->Size=0;
    H->Elements[0]=-1;
    return H;
}
void Insert(ElementType X,PriorityQueue H)
{
    int i;
    if(IsFull(H))
    {
        printf("Priority queue is full");
        return;
    }
    for(i=++H->Size;H->Elements[i/2]>X;i/=2)
        H->Elements[i]=H->Elements[i/2];
    H->Elements[i]=X;
}
ElementType DeleteMin(PriorityQueue H)
{
    int i,Child;
    ElementType MinElement,LastElement;

    if(IsEmpty(H))
    {
        printf("Priority queue is full");
        return H->Elements[0];
    }
    MinElement=H->Elements[1];
    LastElement=H->Elements[H->Size--];
    for(i=1;i*2<=H->Size;i=Child)
    {
        Child=i*2;
        if(Child!=H->Size && H->Elements[Child+1]<H->Elements[Child])
            Child++;
        if(LastElement>H->Elements[Child])
            H->Elements[i]=H->Elements[Child];
        else
            break;
    }
    H->Elements[i]=LastElement;
    return MinElement;
}
ElementType FindMin(PriorityQueue H)
{
    if(H==NULL)
        return -1;
    return H->Elements[1];
}
void Destory(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}
void MakeEmpty(PriorityQueue H)
{
    for(int i=1;i<=H->Capacity;++i)
        H->Elements[i]=0;
    H->Capacity=0;
    H->Size=0;
}
int IsEmpty(PriorityQueue H)
{
    if(H->Size==0)
        return 1;
    else
        return 0;
}
int IsFull(PriorityQueue H)
{
    if(H->Size==H->Capacity)
        return 1;
    else
        return 0;
}
