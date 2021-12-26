 ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* n = head;
        n = n->next;
        head->next = NULL;

        while (n)
        {
            if (n->val <= head->val)
            {
                ListNode* q = n;
                n = n->next;
                q->next = head;
                head = q;
            }
            else
            {
                ListNode* p = head;
                while (p->next)
                {
                    if (n->val >= p->val && n->val <= p->next->val)
                    {
                        ListNode* q = n;
                        n = n->next;
                        q->next = p->next;
                        p->next = q;
                        break;
                    }
                    p = p->next;
                }
                if (!p->next)
                {
                    ListNode* q = n;
                    n = n->next;
                    q->next = NULL;
                    p->next = q;
                }
            }
        }
        return head;
    }
