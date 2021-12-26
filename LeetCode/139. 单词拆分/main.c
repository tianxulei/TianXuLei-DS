bool wordBreak(string s, vector<string>& wordDict) {
        set<string>cidian;
        for (string word : wordDict)
            cidian.insert(word);
        vector<bool>dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && cidian.find(s.substr(j, i - j)) != cidian.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
