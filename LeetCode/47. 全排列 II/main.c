void back(vector<vector<int>>& res,vector<int>& nums,int first,int len){
        if(first==len) res.push_back(nums);
        else{
            set<int> hash;//存储检索过的元素
            for(int i=first;i<len;++i){
                if(hash.find(nums[i])==hash.end()){//当该元素没有检索过，进入回溯
                    swap(nums[i],nums[first]);
                    back(res,nums,first+1,len);
                    swap(nums[i],nums[first]);
                }
                hash.insert(nums[i]);
            }
            hash.clear();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        back(res,nums,0,nums.size());
        return res;
    }
