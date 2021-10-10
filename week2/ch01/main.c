#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    AvlTree T=NULL;
    T=Insert(10,T);
    T=Insert(9,T);
    printf("%d",T->Element);
    printf("%d",T->Right->Element);
    printf("Hello world!\n");
    return 0;
}
