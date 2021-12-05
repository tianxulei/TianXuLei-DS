/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //反转链表
        if(!head) return false;
        if(!head->next) return true;
        struct ListNode* p=head;
        struct ListNode* k;
        struct ListNode* m;
        struct ListNode* n;
        while(p->next)
        {
            if(head->val==p->next->val)
            {
                m=head;n=p->next;
                while(n && n->val==m->val)
                {
                    m=m->next;n=n->next;
                }
                if(!n && m==p->next) return true;
            }
            if(p->next->next && head->val==p->next->next->val)
            {
                m=head;n=p->next->next;
                while(n && n->val==m->val)
                {
                    m=m->next;n=n->next;
                }
                if(!n && m==p->next) return true;
            }
            k=p->next;
            p->next=p->next->next;
            k->next=head;
            head=k;
        }
        return false;
    }
};