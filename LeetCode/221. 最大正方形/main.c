/*在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。*/
//每一个格子的意义：以当前格子为右下角的正方形的边长
    //递推公式：dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]
    //三者中的最小值决定了以当前格子为右下角的正方形的最大值

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<int>>dp(m, vector<int>(n));
        //第一列
        for (int i = 0; i < m; ++i){
            dp[i][0] = matrix[i][0] - '0';
            result = max(result, dp[i][0]);          
        }
        //第一行
        for (int i = 1; i < n; ++i){
            dp[0][i] = matrix[0][i] - '0';   
            result = max(result, dp[0][i]);         
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
    }
