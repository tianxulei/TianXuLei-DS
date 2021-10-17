#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()
{
    PriorityQueue H;
    H=Initialize(30);
    //插入
    printf("Insert:");
    for(int i=0;i<15;++i)
    {
        printf("%d ",i);
        Insert(i,H);
    }
    printf("\n");
    //返回最小
    printf("Min is:");
    printf("%d\n",FindMin(H));
    //删除最小
    printf("Delete min:");
    printf("%d\n",DeleteMin(H));
    //返回最小
    printf("Min is:");
    printf("%d\n",FindMin(H));


    return 0;
}
