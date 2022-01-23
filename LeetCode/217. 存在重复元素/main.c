/*给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

示例 1：
输入：nums = [1,2,3,1]
输出：true*/

bool containsDuplicate(vector<int>& nums) {
        set<int>table;
        for(auto num:nums){
            if(table.find(num)!=table.end())
                return true;
            table.insert(num);
        }
        return false;
    }
