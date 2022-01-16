//计算深度
    int depth(TreeNode* root){
        int level=0;
        while(root){
            root=root->left;
            ++level;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        //左右子树深度一样的话，左子树一定是满的
        if(left==right) return (1<<left)+countNodes(root->right);
        //否则，右子树一定是满的
        else return (1<<right)+countNodes(root->left);
    }
