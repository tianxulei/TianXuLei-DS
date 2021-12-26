vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (i == size - 1)
                    ans.push_back(node->val);
            }
        }
        return ans;
    }
