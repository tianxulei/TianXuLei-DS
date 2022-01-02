void back(vector<vector<int>>& res,vector<int>& nums,int first,int len){
        if(first==len) res.push_back(nums);
        else{
            for(int i=first;i<len;++i){
                swap(nums[i],nums[first]);
                back(res,nums,first+1,len);
                swap(nums[i],nums[first]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        back(res,nums,0,nums.size());
        return res;
    }
