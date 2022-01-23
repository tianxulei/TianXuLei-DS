/*给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"*/

//用于从后向前摘取下一个合法单词
    string pick(string s, int& flag) {
        int size = 0;
        //除去前导空格
        while (flag > -1 && s[flag] == ' ')
            --flag;
        //计算单词长度
        while (flag > -1 && s[flag]!=' ') {
            --flag;
            ++size;
        }
        return s.substr(flag + 1, size);
    }
    string reverseWords(string s) {
        int flag = s.size()-1;
        string ans = pick(s, flag);
        string str = pick(s, flag);
        while (str != "") {
            ans = ans + ' ' + str;
            str = pick(s, flag);
        }
        return ans;
    }
