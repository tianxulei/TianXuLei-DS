TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
    void recover(TreeNode* root) {
        if (!root) return;

        recover(root->left);
        //对比这一个和前一个的值，若不是递增顺序，标记错误
        if (!first && pre && pre->val > root->val)
            first = pre;
        if (first && pre->val > root->val)
            second = root;
        //更新前一个
        pre = root;

        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        recover(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
