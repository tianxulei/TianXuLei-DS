int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int the = 0, result = 0;
        while (the + nums[the] < nums.size() - 1) {
            int max = 0, flag = 0;
            for (int i = 1; i <= nums[the]; ++i) {
                if (i + nums[the + i] > max) {
                    max = i + nums[the + i];
                    flag = i;
                }
            }
            the += flag;
            ++result;
        }
        return result + 1;
        /*int ans = 0;
        int nextMax = 0;
        int max = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if (i == max) {
                ans++;
                max = nextMax;
            }
        }
        return ans;*/
    }
