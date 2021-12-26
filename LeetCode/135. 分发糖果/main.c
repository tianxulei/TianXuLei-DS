int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int>nums(size,1);
        for (int i = 0; i < size-1; ++i)
            if (ratings[i] < ratings[i + 1])
                nums[i + 1] = nums[i] + 1;
        for (int i = size - 1; i > 0; --i)
            if (ratings[i] < ratings[i - 1] && nums[i-1]<=nums[i])
                nums[i - 1] = nums[i] + 1;
        int result = 0;
        for (int i = 0; i < size; ++i)
            result += nums[i];
        return result;
    }
