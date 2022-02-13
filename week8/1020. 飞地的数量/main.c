/*给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。*/
int ans=0,m,n;
    //递归计算链接在边界的陆地
    void dfs(vector<vector<int>>& grid,int x,int y){
        ans++;
        grid[x][y]=0;
        if(x>0 && grid[x-1][y]) dfs(grid,x-1,y);
        if(y>0 && grid[x][y-1]) dfs(grid,x,y-1);
        if(x<m-1 && grid[x+1][y]) dfs(grid,x+1,y);
        if(y<n-1 && grid[x][y+1]) dfs(grid,x,y+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int tmp=0;
        //找出所有陆地
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j])
                    ++tmp;
        //遍历两竖排边界
        for(int i=0;i<n;++i){
            if(grid[0][i]) dfs(grid,0,i);
            if(grid[m-1][i]) dfs(grid,m-1,i);
        }
        //遍历两横排边界
        for(int i=1;i<m-1;++i){
            if(grid[i][0]) dfs(grid,i,0);
            if(grid[i][n-1]) dfs(grid,i,n-1);
        }
        //陆地总数减去连接在边界的陆地数
        return tmp-ans;
    }
