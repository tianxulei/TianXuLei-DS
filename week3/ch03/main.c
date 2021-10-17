#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()
{
    HashTable H;
    Position P;
    H=InitializeTable(100);
    for(int i=0;i<20;++i)
        Insert(i+100,H);
    P=Find(100,H);

    printf("%d",P);
    return 0;
}
