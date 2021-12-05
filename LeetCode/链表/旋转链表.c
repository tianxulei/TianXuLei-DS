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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        struct ListNode* p0=head;
        struct ListNode* p1=head;
        int len=0;
        for(int i=0;i<k;++i)
        {
            p1=p1->next;   
            if(p1==NULL)
            {
                p1=head;             
                len=k%(i+1);
                for(int j=0;j<len;++j)
                    p1=p1->next;
                i=k;
            }
        }
        while(p1->next)
        {
            p0=p0->next;
            p1=p1->next;
        }
        p1->next=head;
        head=p0->next;
        p0->next=NULL;
        return head;
    }
};