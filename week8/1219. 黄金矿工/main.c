/*你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
为了使收益最大化，矿工需要按以下规则来开采黄金：
每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。*/
int path,ans,m,n;
    void dfs(vector<vector<int>>& grid,int x,int y){
        int tmp=grid[x][y],flag=0;
        path+=grid[x][y];
        grid[x][y]=0;
        if(x>0 && grid[x-1][y]){
            dfs(grid,x-1,y);    
            ++flag;        
        }
        if(y>0 && grid[x][y-1]){
            dfs(grid,x,y-1);
            ++flag;            
        }
        if(x<m-1 && grid[x+1][y]){
            dfs(grid,x+1,y);     
            ++flag;       
        }
        if(y<n-1 && grid[x][y+1]){
            dfs(grid,x,y+1);            
            ++flag;
        }
        if(flag==0)
            ans=max(path,ans);       
        grid[x][y]=tmp;
        path-=tmp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
                if(grid[i][j])
                    dfs(grid,i,j);
        }
        return ans;
    }
