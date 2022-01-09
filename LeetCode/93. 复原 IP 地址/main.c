//最后结果
    vector<string>ans;
    //中间值
    string tmp = "";
    //判断这个字符串是否符合条件
    bool judge(string s) {
        if(s.size()==1) return true;
        else if (s.size() > 3 || s[0] == '0') return false;
        else if (s.size() < 3 || s <= "255") return true;
        return false;
    }
    //回溯主体
    void back(int start, int end, int num, string s) {
        //已经有三个“.”并且余下字符串符合条件，就加入ans
        if (num == 3 && judge(s.substr(start))) {
            ans.push_back(tmp.append(s.substr(start)));
            tmp.erase(start + 3);
            return;
        }
        //往后最多找三个字符（一个小地址块最多三个字符）
        for (int i = 1; i <= min(3, end - start); ++i) {
            //找的字符符合条件
            if (judge(s.substr(start, i))) {
                //加上该字符和“.”
                tmp.append(s.substr(start, i));
                tmp += '.';
                //进入回溯
                back(start + i, end, num + 1, s);
                //还原字符串
                tmp.erase(start+num);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return ans;
        back(0, s.size() - 1, 0, s);
        return ans;
    }
