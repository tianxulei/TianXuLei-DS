bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> node;
        queue<int> val;
        node.push(root);
        val.push(root->val);
        TreeNode* p;
        int tmp;
        while (!node.empty()) {
            p = node.front();
            node.pop();
            tmp = val.front();
            val.pop();
            if (!p->left && !p->right && tmp == targetSum)
                return true;
            if (p->left) {
                node.push(p->left);
                val.push(tmp + p->left->val);
            }
            if (p->right) {
                node.push(p->right);
                val.push(tmp + p->right->val);
            }
        }
        return false;
    }

