#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()
{
    PriorityQueue H;
    H=Initialize(30);
    //����
    printf("Insert:");
    for(int i=0;i<15;++i)
    {
        printf("%d ",i);
        Insert(i,H);
    }
    printf("\n");
    //������С
    printf("Min is:");
    printf("%d\n",FindMin(H));
    //ɾ����С
    printf("Delete min:");
    printf("%d\n",DeleteMin(H));
    //������С
    printf("Min is:");
    printf("%d\n",FindMin(H));


    return 0;
}
