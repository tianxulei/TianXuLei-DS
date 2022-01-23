/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]*/

void moveZeroes(vector<int>& nums) {
        int start=0,size=nums.size();
        while(start<size && nums[start]!=0)
            ++start;
        int end=start+1;
        while(end<size){
            if(nums[end]!=0){
                swap(nums[start++],nums[end]);
            }
            end++;
        }
    }
