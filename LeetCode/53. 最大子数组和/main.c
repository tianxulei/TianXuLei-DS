int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (tmp < 0) tmp = 0;
            tmp += nums[i];
            if (tmp > max) max = tmp;
        }
        return max;
    }
