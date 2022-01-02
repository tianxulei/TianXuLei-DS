void test(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        test(root->left,ans);
        ans.push_back(root->val);
        test(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        test(root, ans);
        return ans;
    }

//普通递归
