/*输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"*/

vector<string> summaryRanges(vector<int>& nums) {
        int start=0,end=0,size=nums.size();
        vector<string>ans;
        while(end<size){
            while(end<size-1 && nums[end]+1==nums[end+1])
                ++end;
            if(start!=end)
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            else
                ans.push_back(to_string(nums[start]));
            start=end+1;
            end=start;       
        }
        return ans;
    }
