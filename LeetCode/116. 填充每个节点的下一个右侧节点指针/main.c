Node* connect(Node* root) {
        if(!root) return NULL;
        Node *m = root, *n = m;
        while (m->left) {
            m = m->left;
            n->left->next = n->right;//左右孩子链接
            while (n->next) {
                n->right->next = n->next->left;//和隔壁节点的左孩子链接
                n = n->next;
                n->left->next = n->right;
            }
            n = m;
        }
        return root;
    }
    //通过当前层链接下一层
