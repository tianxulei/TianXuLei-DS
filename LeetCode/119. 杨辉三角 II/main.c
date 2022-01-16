vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(2,vector<int>(rowIndex+1,1));
        int a=1,b=0;
        for(int i=2;i<=rowIndex;++i){
            swap(a,b);
            for(int j=1;j<i;++j){
                dp[a][j]=dp[b][j-1]+dp[b][j];
            }
        }
        return dp[a];
    }
