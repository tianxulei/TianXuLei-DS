void back(vector<vector<int>>& res,vector<int>& nums,int n,int first,int size,int k){
        if(size==k) res.push_back(nums);
        else{
            for(int i=first+1;i<=n;++i){
                nums.push_back(i);
                back(res,nums,n,i,size+1,k);
                nums.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums;
        nums.reserve(k);
        back(res,nums,n,0,0,k);
        return res;
    }
