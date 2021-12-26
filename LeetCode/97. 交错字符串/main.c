bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        vector<vector<bool>> a(m + 1, vector<bool>(n + 1, false));
        a[0][0] = true;
        if (m + n != s3.size()) return false;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i > 0)
                    a[i][j] = (a[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || a[i][j];
                if (j > 0)
                    a[i][j] = (a[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || a[i][j];
            }
        }
        return a[m][n];
    }
