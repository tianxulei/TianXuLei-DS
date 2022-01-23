void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        dfs(root->right);
        swap(root->left,root->right);
        /*TreeNode* tmp=root->left;
        root->left=root->right;
        root->right=tmp;*/
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
