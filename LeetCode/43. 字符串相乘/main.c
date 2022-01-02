string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> a, b, c(m + n);//C用来保存每一位的乘积
        a.reserve(m);
        b.reserve(n);
        for (int i = m - 1; i >= 0; --i)//A倒序存储num1
            a.push_back(num1[i] - '0');
        for (int i = n - 1; i >= 0; --i)//B倒序存储num2
            b.push_back(num2[i] - '0');
        for (int i = 0; i < m; ++i)//每一位相乘存入C
            for (int j = 0; j < n; ++j)
                c[i + j] += a[i] * b[j];
        for (int i = 0; i < m + n - 1; ++i) {//判断进位
            if (c[i] > 9) {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        int k = m + n - 1;
        while (k>0 && c[k] == 0) k--;//除去前导0
        string res;
        res.reserve(k + 1);
        while(k>=0)//反过来存储
            res.push_back(c[k--] + '0');
        return res;
    }
