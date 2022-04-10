class Solution {
public:
    set<char>st;
    bool small(string s){
        int pos=0;
        if(s[0]=='+' || s[0]=='-') pos=1;
        int flag=-1;
        for(int i=pos;i<s.size();++i){
            if(s[i]=='.'){
                if(flag==-1) flag=i;
                else return false;
                continue;
            }
            if(!st.count(s[i])) return false;
        }
        return flag!=-1 && s.size()-pos>1;
    }
    bool big(string s){
        int pos=0;
        if(s[0]=='+' || s[0]=='-') pos=1;
        for(int i=pos;i<s.size();++i)
            if(!st.count(s[i])) return false;
        return s.size()-pos>0;
    }
    bool isNumber(string s) {
        for(int i=0;i<=9;++i) st.insert(i+'0');
        int pos=-1;
        for(int i=0;i<s.size();++i)
            if(s[i]=='e' || s[i]=='E')
                if(pos==-1) pos=i;
                else return false;
        if(pos==0 || pos==s.size()) return false;
        if(pos==-1) return small(s) || big(s);
        return (small(s.substr(0,pos)) || big(s.substr(0,pos))) && big(s.substr(pos+1));
    }
};
