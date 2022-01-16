int numDecodings(string s) {
        int size=s.size();
        if(s[0]=='0') return 0;
        int pre=1,the=1;
        for(int i=1;i<size;++i){
            int tmp=the;
            if(s[i]=='0')
                if(s[i-1]=='1' || s[i-1]=='2') the=pre;
                else return 0;
            else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='1' && s[i]<='6'))
                the=pre+the;
            pre=tmp;
        }
        return the;
    }
