void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int start,int size) {
        ans.push_back(tmp);
        for (int i = start; i < size; ++i) {
            if (i != start && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            dfs(ans, tmp, nums, i + 1, size);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        sort(nums.begin(),nums.end());
        dfs(ans, tmp, nums, 0,nums.size());
        return ans;
    }
