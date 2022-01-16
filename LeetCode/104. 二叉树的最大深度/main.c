int maxDepth(TreeNode* root) {
    if (!root) return 0;
    //递归返回左子树和右子树的最高深度+1
    else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
