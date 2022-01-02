string addBinary(string a, string b) {
        while(b.size()<a.size()) b='0'+b;
        while(a.size()<b.size()) a='0'+a;
        b='0'+b;a='0'+a;
        for(int i=a.size()-1;i>0;--i){
            a[i]=a[i]+b[i]-'0';
            if(a[i]>'1'){
                a[i-1]++;
                a[i]-=2;
            }
        }
        if(a[0]=='0') a.erase(0,1);
        return a;
    }
