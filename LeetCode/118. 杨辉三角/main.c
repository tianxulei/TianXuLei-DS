//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//示例 1:
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back(vector<int>(1));
        ans[0][0]=1;
        for(int i=1;i<numRows;++i){
            ans.push_back(vector<int>(i+1));
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;++j){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
    
//动态规划
