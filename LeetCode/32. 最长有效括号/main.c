/*给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"*/

int longestValidParentheses(string s) {
        int size = s.size(), maxSize = 0;
        vector<int>dp(size,0);
        for (int i = 1; i < size; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i >= 2) dp[i] = dp[i - 2] + 2;
                    else dp[i] = 2;
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
                    else dp[i] = dp[i - 1] + 2;
                }
            }
            maxSize = max(maxSize, dp[i]);
        }
        return maxSize;
    }
