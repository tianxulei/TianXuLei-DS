/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* nums[100];
        int flag=0;
        Node* p=head;
        Node* p1;
        while(p)
        {
            if(p->child)
            {
                if(p->next)
                   nums[flag++]=p->next;   
                p->next=p->child;
                p->child->prev=p;
                p->child=NULL;
            }
            p1=p;
            p=p->next;
        }
        for(int i=flag-1;i>=0;--i)
        {
            p1->next=nums[i];
            nums[i]->prev=p1;
            while(p1->next)
                p1=p1->next;
        }
        return head;
    }
};