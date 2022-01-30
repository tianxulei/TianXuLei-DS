//统计所有小于非负整数 n 的质数的数量。
int countPrimes(int n) {
        vector<int>table(n,1);
        int ans=0;
        for(int i=2;i<n;++i){
            if(table[i]){
                ++ans;
                //如果i是质数,i的倍数一定不是质数
                if((long)i*i<n){
                    for(int j=i*i;j<n;j+=i){
                        table[j]=0;
                    }
                }
            }
        }
        return ans;
    }
