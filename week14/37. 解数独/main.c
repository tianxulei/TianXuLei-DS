class Solution {
public:
    bool lines[9][9],cols[9][9],blos[3][3][9];
    bool flag;
    vector<pair<int,int>>table;
    void dfs(vector<vector<char>>& board,int pos){
        if(pos==table.size()){
            flag=true;
            return;
        }
        int m=table[pos].first,n=table[pos].second;
        for(int i=0;i<9 && !flag;++i){
            if(!lines[m][i] && !cols[n][i] && !blos[m/3][n/3][i]){
                lines[m][i]=cols[n][i]=blos[m/3][n/3][i]=true;
                board[m][n]=i+'0'+1;
                dfs(board,pos+1);
                lines[m][i]=cols[n][i]=blos[m/3][n/3][i]=false;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board){
        memset(lines,false,sizeof(lines));
        memset(cols,false,sizeof(cols));
        memset(blos,false,sizeof(blos));
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    table.emplace_back(i,j);
                }
                else{
                    int tmp=board[i][j]-'0'-1;
                    lines[i][tmp]=cols[j][tmp]=blos[i/3][j/3][tmp]=true;
                }
            }
        }
        dfs(board,0);
    }
};
