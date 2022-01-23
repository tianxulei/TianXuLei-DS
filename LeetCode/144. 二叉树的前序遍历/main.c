vector<int>ans;
    void dfs(TreeNode* root){
        if(!root)
            return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
