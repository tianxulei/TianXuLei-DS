void dfs(vector<int>& ans,TreeNode* root){
        if(!root)
            return;
        dfs(ans,root->left);
        dfs(ans,root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
