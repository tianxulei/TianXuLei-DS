/*给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集*/
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int size, int flag) {
        //该加入集合了
        if (tmp.size() == size) {
            ans.push_back(tmp);
            return;
        }
        //容器遍历完了
        if (flag == nums.size()) 
            return;
        //每次把当前元素加入，然后遍历它后面的元素
        for (int i = flag; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(ans, nums, tmp, size, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int size = nums.size();
        //回溯得到每个长度的子集
        for (int i = 0; i <= size; ++i)
            dfs(ans, nums, tmp, i, 0);
        return ans;
    }
};
