/*找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]*/
vector<vector<int>>ans;
    vector<int>tmp;
    //k个数，和为n，当前个数num,当前和sum,当前数子the
    void dfs(int k, int n, int num, int sum,int the) {
        if (num == k) {
            if (sum == n)
                ans.push_back(tmp);
            return;
        }
        if (sum >= n)
            return;
        for (int i = the+1; i <= 9; ++i) {
            tmp.push_back(i);
            dfs(k, n, num + 1, sum + i,i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 0,0);
        return ans;
    }
