#ifndef HEAD__H_INCLUDED
#define HEAD__H_INCLUDED
#include"math.h"
typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

int NextPrime(int X);
int Hash(ElementType Key,int Size);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);

#endif // HEAD__H_INCLUDED

struct ListNode
{
    ElementType Element;
    Position Next;
};
typedef Position List;
struct HashTbl
{
    int TableSize;
    List *TheLists;
};
int NextPrime(int X)
{
    int a=0,b=X,c=sqrt(b),flag=0;
    while(a!=1)
    {
        for(int i=2;i<c;++i)
        {
            if(b%i!=0)
            {
                ++flag;
            }
        }
        if(flag==(c-2))
                return b;
        else
            flag=0;
        ++b;c=sqrt(b);
    }
    return b;
}
int Hash(ElementType Key,int Size)
{
    return Key/Size;
}
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    if(TableSize<1)
    {
        printf("Table is too small");
        return NULL;
    }
    H=malloc(sizeof(struct HashTbl));
    if(H==NULL)
        printf("Out of space!!!");
    H->TableSize=NextPrime(TableSize);//返回下一个素数
    H->TheLists=malloc(sizeof(List)*H->TableSize);
    if(H->TheLists==NULL)
        printf("Out of space!!!");
    for(int i=0;i<H->TableSize;++i)
    {
        H->TheLists[i]=malloc(sizeof(struct ListNode));
        if(H->TheLists[i]==NULL)
            printf("Out of space!!!");
        else
            H->TheLists[i]->Next=NULL;
    }
    return H;
}
Position Find(ElementType Key,HashTable H)
{
    Position P;
    List L;
    L=H->TheLists[Hash(Key,H->TableSize)];
    P=L->Next;
    while(P!=NULL && P->Element!=Key)
        P=P->Next;
    return P;
}
void Insert(ElementType Key,HashTable H)
{
    Position Pos,NewCell;
    List L;
    Pos=Find(Key,H);
    if(Pos==NULL)
    {
        NewCell=malloc(sizeof(struct ListNode));
        if(NewCell==NULL)
            printf("Out of space!!!");
        else
        {
            L=H->TheLists[Hash(Key,H->TableSize)];
            NewCell->Next=L->Next;
            NewCell->Element=Key;
            L->Next=NewCell;
        }
    }
}
