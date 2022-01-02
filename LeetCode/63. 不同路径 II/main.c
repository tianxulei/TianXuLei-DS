int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int i = 1; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i]) break;
            dp[0][i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        dp[0][0]=1;
        return dp.back().back();
    }
    //动态规划，只用一行保存可节省空间
