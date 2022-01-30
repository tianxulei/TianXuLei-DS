/*给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。*/
vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=1;i<=n;++i){
            if(i%2)
                ans[i]=ans[i-1]+1;
            else
                ans[i]=ans[i>>1];
        }
        return ans;
    }
