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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode* pA=headA;
        struct ListNode* pB=headB;
        int flag=0;
        while(pA && pB)
        {
            if(pA==pB) return pA;
            pA=pA->next;
            pB=pB->next;
            if(flag<2 && !pA) {pA=headB;++flag;}
            if(flag<2 && !pB) {pB=headA;++flag;}
        }
        return NULL;
    }
};