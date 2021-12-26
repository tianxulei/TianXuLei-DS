ListNode* merge(ListNode* T1, ListNode* T2)
    {
        if (!T1) return T2;
        if (!T2) return T1;
        ListNode* q;
        ListNode* p;
        ListNode* p1 = T1;
        ListNode* p2 = T2;
        if (p1->val <= p2->val)
        {
            p = T1;
            q = p;
            p1 = p1->next;
        }
        else
        {
            p = T2;
            q = p;
            p2 = p2->next;
        }
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;
        return q;
    }

    ListNode* sortList(ListNode* head) 
    {
        if (!head) return NULL;
        int size = 1;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            ++size;
        }
        if (fast) size = size * 2 - 1;
        else size = size * 2 - 2;
        if (size < 3)
        {
            if (size == 2 && head->val > head->next->val)
            {
                head->next->next = head;
                head = head->next;
                head->next->next = NULL;
            }
            return head;
        }
        else
        {
            fast = sortList(slow->next);
            slow->next = NULL;
            return merge(sortList(head), fast);
        }
    }
