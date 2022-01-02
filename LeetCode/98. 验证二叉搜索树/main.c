TreeNode* pre;
    bool result = true;
    void isValid(TreeNode* root) {
        if (!root) return;
        isValid(root->left);

        if (pre && pre->val >= root->val)
            result = false;
        pre = root;

        isValid(root->right);
    }
    bool isValidBST(TreeNode* root) {
        isValid(root);
	    return result;
    }
