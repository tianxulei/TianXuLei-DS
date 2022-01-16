int findMin(vector<int>& nums) {
            //m<1 m<r (l,m]
            //m>l m>r (m,r]
            //m>l m<r [l,m)
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<nums[left]){
                left++;
                right=mid;
            }
            else if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return nums[left];
    }
