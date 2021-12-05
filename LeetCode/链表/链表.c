class MyLinkedList
{
    public:
        struct Node
        {
            int val;
            Node* next;
            Node(int x) { val = x, next = nullptr; }
        };
        MyLinkedList()
        {
            size = 0;
            head = new Node(0);
        }
        int get(int index) 
        {
            if (index < 0 || index >= size)
                return -1;
            else
            {
                Node* p = head->next;
                for (int i = 0; i < index; ++i)
                    p = p->next;
                return p->val;
            }
        }
        void addAtHead(int val) //插入头
        {
            Node *newNode = new Node(val);
            newNode->next = head->next;
            head->next = newNode;
            ++size;
        }
        void addAtTail(int val) 
        {
            Node* p = head;
            while (p->next != nullptr)
                p = p->next;
            Node* newNode = new Node(val);
            p->next = newNode;
            ++size;
        }
        void addAtIndex(int index, int val) 
        {
            if (index <= 0)
                addAtHead(val);
            else if (index == size)
                addAtTail(val);
            else if( index < size)
            {
                Node* p = head;
                for (int i = 0; i < index; ++i)
                    p = p->next;
                Node* newNode = new Node(val);
                newNode->next = p->next;
                p->next = newNode;
                ++size;
            }
        }
        void deleteAtIndex(int index) 
        {
            if (index >= 0 && index < size)
            {
                Node* p = head;
                for (int i = 0; i < index; ++i)
                    p = p->next;
                p->next = p->next->next;
                --size;
            }
        }
        void print() //打印
        {
            Node* p = head;
            for (int i = 0; i < size; ++i)
            {
                cout << p->next->val<<" ";
                p = p->next;
            }
            cout << endl;
        }
    private:
        int size;
        Node *head;
};