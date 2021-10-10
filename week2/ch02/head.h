#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
void PrintTree(SearchTree T);

#endif // HEAD_H_INCLUDED
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    printf("树初始化成功\n");
    return NULL;
}
SearchTree Insert(ElementType X,SearchTree T)
{
    if(T==NULL)
    {
        T=malloc(sizeof(struct TreeNode));
        if(T==NULL)
            printf("error malloc!");
        else
        {
            T->Element=X;
            T->Left=T->Right=NULL;
        }
    }
    else if(X<T->Element)
        T->Left=Insert(X,T->Left);
    else if(X>T->Element)
        T->Right=Insert(X,T->Right);
    else
        printf("插入已有元素\n");
    return T;
}
Position Find(ElementType X,SearchTree T)
{
    if(T==NULL)
    {
        printf("%d",X);
        printf("没找到！\n");
        return NULL;
    }
    else if(X<T->Element)
        Find(X,T->Left);
    else if(X>T->Element)
        Find(X,T->Right);
    else
    {
        printf("%d",X);
        printf("找到啦！\n");
    }
    return T;
}
Position FindMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(T->Left==NULL)
        return T;
    else
        return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(T->Right==NULL)
        return T;
    else
        return FindMax(T->Right);
}
SearchTree Delete(ElementType X,SearchTree T)
{
    Position P;
    if(T==NULL)
        printf("this tree is empty\n");
    else if(X<T->Element)
        T->Left=Delete(X,T->Left);
    else if(X>T->Element)
        T->Right=Delete(X,T->Right);
    else
        if(T->Left && T->Right)
        {
            P=FindMin(T->Right);
            T->Element=P->Element;
            T->Right=Delete(T->Element,T->Right);
        }
        else
        {
            P=T;
            if(T->Left==NULL)
                T=T->Right;
            else if(T->Right==NULL)
                T=T->Left;
            free(P);
        }
    return T;
}
void PrintTree(SearchTree T)
{
    if(T!=NULL)
    {
        PrintTree(T->Left);
        printf("%d",T->Element);
        PrintTree(T->Right);
    }
}
