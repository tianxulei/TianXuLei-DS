#include <stdio.h>
#include <stdlib.h>
#include "head..h"
int main()
{
    HashTable H;
    Position P=malloc(sizeof(struct ListNode));
    H=InitializeTable(10);
    for(int i=0;i<5;++i)
        Insert(i,H);
    P=Find(3,H);
    printf("%d",P->Element);
    return 0;
}
