bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == q) return true;//两个都为空
	    else if (!p || !q) return false;//其中一个为空
	    if (p->val != q->val) return false;//两个数不同
	    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//递归判断左右子树
    }

//递归判断左右子树是否一样
