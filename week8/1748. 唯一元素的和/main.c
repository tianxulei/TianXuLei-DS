/*给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
请你返回 nums 中唯一元素的 和 。*/
int sumOfUnique(vector<int>& nums) {
        map<int,int>mp;
        for(auto num:nums)
            mp[num]++;
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();++it)
            if(it->second==1)
                ans+=it->first;
        return ans;
    }
