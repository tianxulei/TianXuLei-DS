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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next ||!head->next->next) return head;
        struct ListNode* p1=head;
        struct ListNode* pB=p1->next;
        struct ListNode* p2=p1->next;
        struct ListNode* p3=p2->next;
        bool flag=1;
        while(p3)
        {
            if(flag) {p1->next=p3;p1=p1->next;}
            else {p2->next=p3;p2=p2->next;}
            p3=p3->next;
            flag=!flag;
        }
        p1->next=pB;
        p2->next=NULL;
        return head;
    }
};