给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: rowIndex = 3
输出: [1,3,3,1]

vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(2,vector<int>(rowIndex+1,1));
        int a=1,b=0;
        for(int i=2;i<=rowIndex;++i){
            swap(a,b);
            for(int j=1;j<i;++j){
                dp[a][j]=dp[b][j-1]+dp[b][j];
            }
        }
        return dp[a];
    }
