#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include"math.h"
typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HasTbl *HashTable;

int NextPrime(int X);//找到下一个素数
int Hash(ElementType Key,int Size);//找Key位置
HashTable InitializeTable(int TableSize);//做空表
void DestroyTable(HashTable H);//清空表
Position Find(ElementType Key,HashTable H);//找元素
void Insert(ElementType Key,HashTable H);//插入
HashTable Rehash(HashTable H);//再散列
ElementType Retrieve(Position P);

#endif // HEAD_H_INCLUDED
enum KindOfEntry{Legitimate,Empty,Deleted};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HasTbl
{
    int TableSize;
    Cell *TheCells;
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
    return Key%Size;
}
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    if(TableSize<10)
    {
        printf("Table size too small");
        return NULL;
    }
    H=malloc(sizeof(struct HasTbl));
    if(H==NULL)
        printf("Out of space!!!");
    H->TableSize=NextPrime(TableSize);
    H->TheCells=malloc(sizeof(Cell)*H->TableSize);
    if(H->TheCells==NULL)
        printf("Out of space!!!");
    for(int i=0;i<H->TableSize;i++)
        H->TheCells[i].Info=Empty;
    return H;
}
Position Find(ElementType Key,HashTable H)
{
    Position CurrentPos;
    int CollisionNum;
    CollisionNum=0;
    CurrentPos=Hash(Key,H->TableSize);
    while(H->TheCells[CurrentPos].Info!=Empty && H->TheCells[CurrentPos].Element!=Key)
    {
        CurrentPos+=2*++CollisionNum-1;
        if(CurrentPos>=H->TableSize)
            CurrentPos-=H->TableSize;
    }
    return CurrentPos;
}
void Insert(ElementType Key,HashTable H)
{
    Position Pos;
    Pos=Find(Key,H);
    if(H->TheCells[Pos].Info!=Legitimate)
    {
        H->TheCells[Pos].Info=Legitimate;
        H->TheCells[Pos].Element=Key;
    }
}
HashTable Rehash(HashTable H)
{
    int i,OldSize;
    Cell *OldCells;
    OldCells=H->TheCells;
    OldSize=H->TableSize;
    H=InitializeTable(2*OldSize);
    for(i=0;i<OldSize;++i)
        if(OldCells[i].Info==Legitimate)
            Insert(OldCells[i].Element,H);
    free(OldCells);
    return H;
}
