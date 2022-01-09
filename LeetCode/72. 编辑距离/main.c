/*给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/

//dp[i][j]代表word1,word2的前i,j个字符的编辑距离
    //dp[i][j]=dp[i-1][j]+1;
    //word1,word2的前i,j个字符的编辑距离小于等于word1,word2的前i-1,j个字符的编辑距离+1
    //因为只需要在word1后面插入一个字符，编辑距离+1即可（另外两种情况同理，最后取最小值）

    int minDistance(string word1, string word2) {
        //如果一个字符串是空的
        if(word1.empty() || word2.empty())
            return word1.size()+word2.size();

        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 1; i <= n; ++i) dp[0][i] = i;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }

        return dp[m][n];
    }
