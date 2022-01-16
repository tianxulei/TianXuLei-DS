编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int row=-1;
        for(int i=0;i<m;++i){
            if(matrix[i].back()>=target){
                row=i;
                break;
            }
        }
        if(row==-1)
            return false;
        for(int i=0;i<n;++i){
            if(matrix[row][i]>=target)
                return matrix[row][i]==target;
        }
        return true;
    }
