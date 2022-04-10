class Solution {
public:
    vector<vector<string>>ans;
    bool judge(vector<vector<bool>>&table,int flag,int i,int n){
        for(int k=1;k<=flag;++k)
            if(table[i][flag-k]) return false;
        int a=min(flag,i),b=min(flag,n-i-1);
        for(int k=1;k<=a;++k)
            if(table[i-k][flag-k]) return false;
        for(int k=1;k<=b;++k)
            if(table[i+k][flag-k]) return false;
        return true;
    }
    void dfs(vector<vector<bool>>&table,int flag,int n){
        if(flag==n){
            vector<string>tmp;
            for(int i=0;i<n;++i){
                string str="";
                for(int j=0;j<n;++j)
                    if(table[i][j]) str+='Q';
                    else str+='.';
                tmp.push_back(str);
            }
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<n;++i){
            if(judge(table,flag,i,n)){
                table[i][flag]=true;
                dfs(table,flag+1,n);
                table[i][flag]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>>table(n,vector<bool>(n,false));
        dfs(table,0,n);
        return ans;
    }
};
