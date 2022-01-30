/*给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5*/
//上滤
    void test(vector<int>& nums, int size, int flag) {
        int l = flag * 2 + 1, r = l + 1, max = flag;
        if (l<size && nums[l]>nums[max])
            max = l;
        if (r<size && nums[r]>nums[max])
            max = r;
        if (max != flag) {
            swap(nums[flag], nums[max]);
            test(nums, size, max);
        }
    }
    //构建最大堆
    void build(vector<int>& nums, int size) {
        for (int i = size / 2; i >= 0; --i) {
            test(nums, size, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        build(nums, size);
        //删除最大值k-1次
        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[size - 1]);
            --size;
            test(nums, size, 0);
        }
        return nums[0];
    }
