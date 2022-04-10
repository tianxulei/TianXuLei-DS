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
    struct tmp
    {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, tmp>que;
        for (int i = 0; i < lists.size(); ++i)
            if(lists[i]!=nullptr) que.push(lists[i]);
        ListNode* ans=nullptr;
        if(!que.empty()) {
            ans= que.top();
            que.pop();    
            if(ans->next!=nullptr) que.push(ans->next);        
        }
        ListNode* p = ans;
        while (!que.empty()) {
            ListNode* tmp = que.top();
            que.pop();
            if (tmp->next!=nullptr) que.push(tmp->next);
            p->next = tmp;
            p = p->next;
        }
        return ans;
    }
};
