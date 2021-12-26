ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        ListNode* min=NULL;
        ListNode* p=head;
        while (p && p->val < x)
        {
            min = p;        
            p=p->next;    
        }
        while (p && p->next)
        {
            if (p->next->val < x)
            {
                ListNode* t = p->next;
                p->next = t->next;
                if (min)
                {
                    t->next = min->next;
                    min->next = t;
                    min = min->next;
                }
                else
                {
                    t->next = head; 
                    head = t;
                    min = t;
                }
            }
            else
                p = p->next;
        }
        return head;
    }
