TreeNode* build(vector<int>& nums,int begin,int end){
        if(begin>end)
            return NULL;
        int mid=(begin+end)>>1;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=build(nums,begin,mid-1);
        root->right=build(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size=nums.size();
        int mid=size>>1;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=build(nums,0,mid-1);
        root->right=build(nums,mid+1,size-1);
        return root;
    }
