#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    Position T=NULL;
    Position P=NULL;
    T=MakeEmpty(T);
    for(int i=2;i<=10;++i)
    {
        T=Insert(i,T);
        printf("成功插入:");
        printf("%d\n",i);
    }
    T=Insert(2,T);
    P=Find(10,T);
    P=Find(11,T);
    P=FindMin(T);
    printf("最大值是:");
    printf("%d\n",P->Element);
    P=FindMax(T);
    printf("最小值是:");
    printf("%d\n",P->Element);
    printf("删除：");
    printf("%d\n",10);
    T=Delete(10,T);
    P=Find(10,T);
    PrintTree(T);
    return 0;
}
