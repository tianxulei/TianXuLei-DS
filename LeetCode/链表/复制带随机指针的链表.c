/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* p=head;
        Node* Head=new Node(p->val);
        Node* p1=Head;
        p=p->next;
        while(p)
        {
            Node* k=new Node(p->val);
            p1->next=k;
            p=p->next;
            p1=p1->next;
        }
        Node* k=head;
        Node* l=Head;
        Node* q;
        while(k)
        {
            q=k->random;
            p1=Head;
            p=head;
            while(p!=q)
            {
                p=p->next;
                p1=p1->next;
            }
            l->random=p1;
            l=l->next;
            k=k->next;
        }
        return Head;
    }
};