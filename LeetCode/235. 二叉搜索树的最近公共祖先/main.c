//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int m=p->val,n=q->val;
        if(p->val>q->val)
            swap(m,n);
        while(root->val<m || root->val>n){
            if(root->val<m)
                root=root->right;
            else
                root=root->left;
        }
        return root;
    }
