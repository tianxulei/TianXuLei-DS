/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。*/

bool isAnagram(string s, string t) {
        int a=s.size();
        if(a!=t.size())
            return false;
        int c[26]={0};
        for(int i=0;i<a;++i){
            c[s[i]-'a']++;
            c[t[i]-'a']--;
        }
        for(int i=0;i<26;++i){
            if(c[i]!=0)
                return false;
        }
        return true;
    }
