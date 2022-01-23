//给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

int missingNumber(vector<int>& nums) {
        int size=nums.size(),k=(size+1)*size/2;
        for(int i=0;i<size;++i)
            k-=nums[i];
        return k;
    }
