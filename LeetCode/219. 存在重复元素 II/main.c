/*给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

示例 1：
输入：nums = [1,2,3,1], k = 3
输出：true*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>table;
        int size=nums.size();
        for(int i=0;i<size;++i){
            if(table.find(nums[i])==table.end() && i-table[nums[i]]<=k){
                return true;
            }
            table[nums[i]]=i;
        }
        return false;
    }
