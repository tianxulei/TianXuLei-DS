/*给定一个整数数组  nums，处理以下类型的多个查询:
计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )

示例 1：
输入：
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
输出：
[null, 1, -1, -3]*/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size=nums.size();
        ans.push_back(0);
        for(int i=0;i<size;++i)
            ans.push_back(ans.back()+nums[i]);
    }
    
    int sumRange(int left, int right) {
        return ans[right+1]-ans[left];
    }
    vector<int>ans;
};
