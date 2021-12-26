int rob(vector<int>& nums) {
        vector<int>dp;
        dp.reserve(4);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0) dp.push_back(nums[0]);
            else if (i == 1) dp.push_back(max(nums[0], nums[1]));
            else if (i == 2) dp.push_back(max(nums[0] + nums[2], nums[1]));
            else {
                dp.push_back(max(dp[1] + nums[i], max(dp[2], dp[0] + nums[i])));
                dp.erase(dp.begin());
            }
        }
        return dp.back();
    }
