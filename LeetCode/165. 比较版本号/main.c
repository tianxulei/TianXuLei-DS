/*示例 1：
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"

示例 2：
输入：version1 = "1.0", version2 = "1.0.0"
输出：0
解释：version1 没有指定下标为 2 的修订号，即视为 "0"*/

//摘取合法修订号
    string pick(string version,int& flag) {
        //要摘取的长度
        int size = 0;
        while (flag+size < version.size() && version[flag+size] != '.')
            ++size;
        //摘取
        string str = version.substr(flag, size);
        //除去前导0
        for (int i = 1; i < size; ++i) {
            if (str[0] == '0')
                str.erase(0, 1);
            else
                break;
        }
        //更新下标
        flag = flag + size + 1;
        return str;
    }
    //判断大小
    int judge(string str1, string str2) {
        if (str1.size() > str2.size())
            return 1;
        if (str1.size() < str2.size())
            return -1;
        if (str1 > str2)
            return 1;
        if (str1 < str2)
            return -1;
        return 0;
    }
    int compareVersion(string version1, string version2) {
        //字符串大小
        int size1 = version1.size(), size2 = version2.size();
        int flag1 = 0, flag2 = 0, ans = 2;
        string str1, str2;
        //两个字符串都还没扫描完
        while (flag1 < size1 && flag2 < size2) {
            str1 = pick(version1, flag1);
            str2 = pick(version2, flag2);
            ans = judge(str1, str2);
            if (ans != 0)
                return ans;
        }
        //version1还没扫描完
        while(flag1 < size1) {
            str1 = pick(version1, flag1);
            if (str1 != "0")
                return 1;
        }
        //version2还没扫描完
        while (flag2 < size2) {
            str2 = pick(version2, flag2);
            if (str2 != "0")
                return -1;
        }
        return 0;
    }
