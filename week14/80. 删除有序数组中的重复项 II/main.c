class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums[0],flag=1,pos=1;
        while(nums.begin()+pos!=nums.end()){
            if(nums[pos]==num) flag++;
            else{
                num=nums[pos];
                flag=1;
                ++pos;
                continue;
            }
            if(flag>2)
                nums.erase(nums.begin()+pos);
            else ++pos;
        }
        return nums.size();
    }
};
