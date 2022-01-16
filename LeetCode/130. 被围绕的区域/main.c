//没被包围的一定是挨着边界的，所以只要从边界找到‘O’，再往里面找就行
    int m,n;
    //类似种子填充算法，递归找四个方向符合条件的位置
    void dfs(vector<vector<char>>& board,int x,int y){
        if(board[x][y]=='O'){
            board[x][y]='A';//标记这个位置已经被搜索过
            if(x>0) dfs(board,x-1,y);//上
            if(x<m-1) dfs(board,x+1,y);//下
            if(y>0) dfs(board,x,y-1);//左
            if(y<n-1) dfs(board,x,y+1);//右
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size(),n=board[0].size();
        //遍历边界点
        for(int i=0;i<m;++i){
            if(board[i][0]=='O') 
                dfs(board,i,0);
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
        }
        for(int i=1;i<n-1;++i){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[m-1][i]=='O')
                dfs(board,m-1,i);
        }
        //把标记的A变为O，把剩下的O变为X
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='A')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
