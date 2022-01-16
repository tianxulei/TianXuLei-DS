bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(nums[mid]==target)
                return true;
            if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                ++left;
                --right;
            }
           else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
