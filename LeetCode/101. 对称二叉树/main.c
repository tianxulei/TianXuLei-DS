给你一个二叉树的根节点 root ， 检查它是否轴对称。
//只要递归判断两棵树的左子树和右子树，右子树和左子树是否对称
    bool dfs(TreeNode* left,TreeNode*right){
        if(!right && !left) return true;
        if(!right || !left) return false;
        return left->val==right->val && dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
