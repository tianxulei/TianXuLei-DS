/*给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

输入：s = "egg", t = "add"
输出：true*/

bool isIsomorphic(string s, string t) {
        map<char,char>table;
        set<char>str;
        for(int i=0;i<s.size();++i){
            if(table.find(s[i])==table.end()){
                if(str.find(t[i])!=str.end())
                    return false;
                table[s[i]]=t[i];  
                str.insert(t[i]);
                continue;              
            }
            if(table[s[i]]==t[i])
                continue;
            return false;
        }
        return true;
    }
