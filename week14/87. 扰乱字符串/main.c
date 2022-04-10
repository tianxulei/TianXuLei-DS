class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size=s1.size();
        vector<vector<vector<bool>>>dp(size,vector<vector<bool>>(size,vector<bool>(size+1,false)));
        for(int i=0;i<size;++i)
            for(int j=0;j<size;++j)
                dp[i][j][1]=(s1[i]==s2[j]);
        for(int len=2;len<=size;++len)
            for(int i=0;i<=size-len;++i)
                for(int j=0;j<=size-len;++j)
                    for(int k=1;k<=len-1;++k)
                        if(dp[i][j][k] && dp[i+k][j+k][len-k]){
                            dp[i][j][len]=true;
                            break;
                        }
                        else if(dp[i][j+len-k][k] && dp[i+k][j][len-k]){
                            dp[i][j][len]=true;
                            break;
                        }
        return dp[0][0][size];
    }
};
