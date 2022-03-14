/*给定两个字符串 s 和 t ，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>ss(26,0),tt(26,0);
        for(auto a:s)
            ss[a-'a']++;
        for(auto a:t)
            tt[a-'a']++;
        for(int i=0;i<26;++i)
            if(ss[i]!=tt[i])
                return (char)('a'+i);
        return 'a';
    }
};
