bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //从右上角开始，向左走减小，向下走增大
        int m=matrix.size(),n=matrix[0].size();
        int x=0,y=n-1;
        while(x<m && y>=0){
            if(matrix[x][y]>target) --y;
            else if(matrix[x][y]<target) ++x;
            else return true;
        }
        return false;
    }
