#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

struct TreeNode;
typedef struct TreeNode* PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(void);//初始化
ElementType FindMin(PriorityQueue H);//找最小值
int IsEmpty(PriorityQueue H);//判断空
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);//合并
void SwapChildren(PriorityQueue H);//交换儿子
#define Insert(X,H)(H=Insert1((X),H))
#define DeleteMin(H)(H=DeleteMin1(H))
PriorityQueue Insert1(ElementType X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif // HEAD_H_INCLUDED

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};
int IsEmpty(PriorityQueue H)
{
    if(H==NULL)
        return 1;
    else
        return 0;
}
PriorityQueue Initialize(void)
{
    PriorityQueue H=malloc(sizeof(struct TreeNode));
    H->Element=100;
    H->Left=NULL;
    H->Right=NULL;
    H->Npl=0;
    return H;
}
void SwapChildren(PriorityQueue H)
{
    PriorityQueue t;
    t=H->Left;
    H->Left=H->Right;
    H->Right=t;
    free(t);
}
ElementType FindMin(PriorityQueue H)
{
    if(IsEmpty(H))
        return -1;
    else
        return H->Element;
}
static PriorityQueue Merge1(PriorityQueue H1,PriorityQueue H2)
{
    if(H1->Left==NULL)
        H1->Left=H2;
    else
    {
        H1->Right=Merge(H1->Right,H2);
        if(H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl=H1->Right->Npl+1;
    }
    return H1;
}
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2)
{
    if(H1==NULL)
        return H2;
    if(H2==NULL)
        return H1;
    if(H1->Element<H2->Element)
        return Merge1(H1,H2);
    else
        return Merge1(H2,H1);
}
PriorityQueue Insert1(ElementType X,PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode=malloc(sizeof(struct TreeNode));
    if(SingleNode==NULL)
        printf("Out of space!!!");
    else
    {
        SingleNode->Element=X;
        SingleNode->Npl=0;
        H=Merge(SingleNode,H);
    }
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap,RightHeap;
    if(IsEmpty(H))
    {
        printf("Priority queue is empty");
        return H;
    }
    LeftHeap=H->Left;
    RightHeap=H->Right;
    free(H);
    return Merge(LeftHeap,RightHeap);
}
