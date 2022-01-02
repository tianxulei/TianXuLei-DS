vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=0;i<pow(2,nums.size());++i){
            res.push_back(vector<int>());
            int k=0,j=i;
            while(j!=0){
                if(j%2) res[i].push_back(nums[k]);
                ++k;
                j=j>>1;
            }
        }
        return res;
    }
