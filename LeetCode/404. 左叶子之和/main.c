/*计算给定二叉树的所有左叶子之和。*/
int sum=0;
    void dfs(TreeNode* root,int flag){
        if(!root)
            return;
        if(!root->left && !root->right && flag)
            sum+=root->val;
        dfs(root->left,1);
        dfs(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
