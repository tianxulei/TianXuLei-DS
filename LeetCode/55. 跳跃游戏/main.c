bool canJump(vector<int>& nums) {
        int Max = 0;
        int nextMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nextMax = max(nextMax, i + nums[i]);
            if (i == Max) Max = nextMax;
            else if(i>Max) return false;
            if (nextMax>=nums.size()-1) return true;
        }
        if(nums.size()==1) return true;
        return false;
    }
