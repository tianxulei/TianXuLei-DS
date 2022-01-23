/*给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true*/

//摘取单词函数
    string pick(string s, int& flag) {
        if(flag>=s.size())
            return "";
        int size = 0;
        for (auto it = s.begin() + flag; it != s.end() && *it != ' '; ++it) {
            ++size;
        }
        string str = s.substr(flag, size);
        flag = flag + size + 1;
        return str;
    }
    bool wordPattern(string pattern, string s) {
        //映射关系
        map<char, string>table;
        map<string, char>table2;
        //s下标
        int flag = 0;
        int size = pattern.size();
        for (int i = 0; i < size; ++i) {
            //摘取单词
            string str = pick(s, flag);
            //如果s摘取完了但pattern还没完
            if(str=="") return false;
            //如果不存在映射关系，就新建
            if (table.find(pattern[i]) == table.end()) {
                if (table2.find(str) == table2.end()) {
                    table[pattern[i]] = str;
                    table2[str] = pattern[i];
                }
                else
                    return false;
            }
            //否则，判断映射是否正确
            else if (table[pattern[i]] != str)
                return false;
        }
        //如果pattern完了，但s还没完
        if(flag<s.size()) 
            return false;
        return true;
    }
