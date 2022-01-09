//动态规划
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();//层数
        vector<vector<int>> dp(2, vector<int>(size));//需要两个窗口滑动交换(因为一个值的变化会对隔壁值有影响,只能先另外一个窗口存储)
        dp[0][0] = triangle[0][0];//第一层
        for (int i = 1; i < size; ++i) {
            int tmp_one = i % 2, tmp_two = (i + 1) % 2;//用于判断使用哪个窗口
            dp[tmp_one][0] = dp[tmp_two][0] + triangle[i][0];//每一层第一个
            dp[tmp_one][i] = dp[tmp_two][i - 1] + triangle[i][i];//每一层最后一个
            for (int j = 1; j < i; ++j) {//中间的,值由j,j-1决定
                dp[tmp_one][j] = min(dp[tmp_two][j], dp[tmp_two][j - 1]) + triangle[i][j];
            }
        }
        int tmp = (size + 1) % 2;//判断哪个是最后的窗口
        int result = dp[tmp][0];
        for (int i = 1; i < size; ++i) {//找到最后窗口里的最小值
            result = min(result, dp[tmp][i]);
        }
        return result;
    }
