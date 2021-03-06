/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
            if(head==NULL || head->next==NULL)
                return NULL;
            ListNode* p1=head;
            ListNode* p2=head;
            p1=p1->next;
            p2=p2->next->next;
            while(p2!=NULL && p2->next!=NULL && p1!=p2)
            {
                p2=p2->next->next;
                p1=p1->next;
            }
            if(p1!=p2)
                return NULL;
            p1=head;
            while(p1!=p2)
            {
                p1=p1->next;
                p2=p2->next;
            }
            return p1;
    }
};