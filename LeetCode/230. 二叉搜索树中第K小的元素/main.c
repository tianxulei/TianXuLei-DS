/*给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。*/
int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            --k;
            if(!k)
                break;
            root=root->right;
        }
        return root->val;
    }
