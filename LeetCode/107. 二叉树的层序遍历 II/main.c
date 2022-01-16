给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //定义返回值
        vector<vector<int>>ans;
        //传入空树的情况
        if(!root)
            return ans;
        //层序遍历队列
        queue<TreeNode*>que;
        que.push(root);
        int j=0;//层数
        //开始层序遍历
        while(!que.empty()){
            ans.push_back(vector<int>());
            int size=que.size();
            for(int i=0;i<size;++i){
                TreeNode* tmp=que.front();
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
                //ans.back().push_back(tmp->val);
                ans[j].push_back(tmp->val);
            }
            ++j;
        }
        //反转
        reverse(ans.begin(),ans.end());
        return ans;
    }
