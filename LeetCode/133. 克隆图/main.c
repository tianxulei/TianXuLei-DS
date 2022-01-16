//存储已经拷贝过的节点指针
    Node* used[101];
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        //如果该节点已经拷贝过，直接返回
        if(used[node->val]) return used[node->val];
        //创建未拷贝过的新节点
        Node *p=new Node(node->val);
        //把新节点存入used
        used[p->val]=p;
        //拷贝neighbors中的节点
        for(int i=0;i<node->neighbors.size();++i)
            p->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return p;
    }
