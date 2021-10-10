#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree T);
int Height(Position P);
int Max(int a,int b);
Position SingleRotateWithLeft(Position k2);
Position DoubleRotateWithLeft(Position k3);
AvlTree Insert(ElementType X,AvlTree T);

#endif // HEAD_H_INCLUDED
struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};
AvlTree MakeEmpty(AvlTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
int Max(int a,int b)
{
    return (a>b)?a:b;
}
int Height(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->Height;
}
Position SingleRotateWithLeft(Position k2)
{
    Position k1=k2->Left;
    k2->Left=k1->Right;
    k1->Right=k2;
    k2->Height=Max(Height(k2->Left),Height(k2->Right))+1;
    k1->Height=Max(Height(k1->Left),k2->Height)+1;
    return k1;
}
Position DoubleRotateWithLeft(Position k3)
{
    k3->Left=SingleRotateWithLeft(k3->Left);
    return SingleRotateWithLeft(k3);
}
AvlTree Insert(ElementType X,AvlTree T)
{
    if(T==NULL)
    {
        T=malloc(sizeof(struct AvlNode));
        T->Element=X;
        T->Height=0;
        T->Left=NULL;
        T->Right=NULL;
    }
    else if(X<T->Element)
    {
        T->Left=Insert(X,T->Left);
        if(Height(T->Left)-Height(T->Right)==2)
        {
            if(X<T->Left->Element)
                T=SingleRotateWithLeft(T);
            else
                T=DoubleRotateWithLeft(T);
        }

    }
    else if(X>T->Element)
    {
        T->Right=Insert(X,T->Right);
        if(Height(T->Right)-Height(T->Left)==2)
        {
            if(X<T->Left->Element)
                T=SingleRotateWithLeft(T);
            else
                T=DoubleRotateWithLeft(T);
        }
    }
    T->Height=Max(Height(T->Left),Height(T->Right))+1;
    return T;
}
