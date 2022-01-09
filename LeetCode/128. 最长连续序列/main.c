int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int result = 1;
        vector<int>flag;
        map<int, int>hash;//第二个int存储在flag里面的下标，下表里面是连续的个数
        for (int num : nums)
            hash[num] = -1;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (hash.count(it->first - 1)) {//如果它减一也在里面，就让他们指向相同的flag下标
                it->second = hash[it->first - 1];
                flag[it->second]++;
                result = max(result, flag[it->second]);
            }
            else {
                it->second = flag.size();
                flag.push_back(1);
            }
        }
        return result;
    }
