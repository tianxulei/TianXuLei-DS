int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (auto it = nums.begin()+1; it != nums.end(); ++it)
            ans = ans ^ *it;
        return ans;
    }
    //同一数字按位异或最终为0，所以它们会两两抵消，最终的值就是只出现一次的值
