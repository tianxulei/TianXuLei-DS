/*给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。
返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,tmp=nums[0];
        for(int i=1;i<nums.size();++i){
            ans=max(ans,nums[i]-tmp);
            tmp=min(tmp,nums[i]);
        }
        return ans==0?-1:ans;
    }
};
