/*实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器*/

TreeNode* tmp;
    stack<TreeNode*>table;
    BSTIterator(TreeNode* root) {
        tmp=root;
    }
    
    int next() {
        while(tmp){
            table.push(tmp);
            tmp=tmp->left;
        }
        tmp=table.top();
        table.pop();
        int a=tmp->val;
        tmp=tmp->right;
        return a;
    }
    
    bool hasNext() {
        return tmp || !table.empty();
    }
