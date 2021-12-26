int maxProduct(vector<int>& nums) {
        int Max = nums[0];
        int dpmax = nums[0], dpmin = nums[0];
        int a;
        for (int i = 1; i < nums.size(); ++i)
        {
            a = max(dpmax * nums[i], max(dpmin * nums[i], nums[i]));
            dpmin = min(dpmax * nums[i], min(dpmin * nums[i], nums[i]));
            dpmax = a;
            if (dpmax > Max) Max = dpmax;
        }
        return Max;
    }
