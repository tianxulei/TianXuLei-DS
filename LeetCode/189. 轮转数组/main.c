/*给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]*/

void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;
        vector<int>ans(k);
        //存储最后面k个元素
        for(int i=0;i<k;++i){
            ans[i]=nums[size-k+i];
        }
        //剩余元素往后移动k
        for(int i=size-1;i>=k;--i){
            nums[i]=nums[i-k];
        }
        //存储的元素放到最前面
        for(int i=0;i<k;++i){
            nums[i]=ans[i];
        }
    }
