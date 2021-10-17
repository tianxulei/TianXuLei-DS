#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()
{

    PriorityQueue P=Initialize();
    printf("Insert:");
    Insert(1,P);
    printf("%d\n",P->Element);
    printf("FindMin:");
    printf("%d\n",FindMin(P));
    printf("Insert:");
    Insert(2,P);
    printf("%d\n",P->Element);
    printf("DeleteMin\n");
    DeleteMin(P);
    printf("FindMin:");
    printf("%d\n",FindMin(P));
    return 0;
}
