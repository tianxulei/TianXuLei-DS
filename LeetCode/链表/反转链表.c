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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        struct ListNode* p=head;
        struct ListNode* k;
        while(p->next)
        {
            k=p->next;
            p->next=p->next->next;
            k->next=head;
            head=k;
        }
        return head;
    }
};