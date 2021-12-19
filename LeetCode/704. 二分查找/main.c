class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,enter;
        while(left<=right)
        {
            enter=(left+right)/2;
            if(nums[enter]<target)
                left=enter+1;
            else if(nums[enter]>target)
                right=enter-1;
            else
                return enter;
        }
        return -1;
    }
};
