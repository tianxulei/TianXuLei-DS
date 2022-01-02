int myAtoi(string s) {
        map<char, int>a{ {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} ,{'+',-1}, {'-',-1} };
        //跳过前导空格
        int first = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == ' ') ++first;
            else break;
        if (a.find(s[first]) == a.end()) return 0;
        //找符号
        int fuhao = 1;
        if (s[first] == '-') { fuhao = -1; ++first; }
        else if (s[first] == '+') { fuhao = 1; ++first; }
        //除去前导0
        for (int i = first; i < s.size(); ++i)
            if (s[i] == '0') ++first;
            else break;
        if (a[s[first]] < 1 || a[s[first]] > 9) return 0;
        //计算最终值
        long long result = 0;
        for (int i = first; i < s.size(); ++i)
            if (a.find(s[i]) != a.end() && a[s[i]] >= 0 && a[s[i]] <= 9) {
                result = result * 10 + a[s[i]];
                if (result > INT_MAX) break;
            }   
            else break;
        result = fuhao * result;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int)result;
    }
