vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>nums;
        if(!root) return nums;
        queue<TreeNode*>que;
        que.push(root);
        int layer=0;
        int direct=0;
        while(!que.empty()){
            int size=que.size();
            vector<int>a;
            a.reserve(size);
            nums.push_back(a);
            if(direct==0){
                for(int i=0;i<size;++i){
                    TreeNode* p=que.front();
                    que.pop();
                    nums[layer].push_back(p->val);
                    if(p->left) que.push(p->left);
                    if(p->right) que.push(p->right);
                }
                ++direct;
            }
            else{
                for(int i=0;i<size;++i){
                    TreeNode* p=que.front();
                    que.pop();
                    nums[layer].insert(nums[layer].begin(),p->val);
                    if(p->left) que.push(p->left);
                    if(p->right) que.push(p->right);
                }
                --direct;
            }
            ++layer;
        }
        return nums;
    }
