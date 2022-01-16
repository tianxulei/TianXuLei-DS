ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        if(left==1){
            ListNode *flag=head;
            int size=right-left;
            for(int i=0;i<size;++i){
                ListNode *p=flag->next;
                flag->next=p->next;
                p->next=head;
                head=p;
            }
            return head;
        }
        //left的前驱节点
        ListNode *p=head;
        for(int i=2;i<left;++i)
            p=p->next;
        //这是left节点
        ListNode *flag=p->next;
        int size=right-left;
        for(int i=0;i<size;++i){
             ListNode *q=flag->next;
             flag->next=q->next;
             q->next=p->next;
             p->next=q;
        }
        return head;
    }
