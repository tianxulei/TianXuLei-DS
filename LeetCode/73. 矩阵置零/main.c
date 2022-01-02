void setZeroes(vector<vector<int>>& matrix) {
        //遍历矩阵,存储值为0的x,y坐标,之后将这些坐标对应的行和列置0
        set<int>x,y;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (matrix[i][j] == 0) {
                    x.insert(i);
                    y.insert(j);
                }
        while (!x.empty()) {
            int X = *x.begin();
            x.erase(x.begin());
            for (int i = 0; i < n; ++i)
                matrix[X][i] = 0;
        }
        while (!y.empty()) {
            int Y = *y.begin();
            y.erase(y.begin());
            for (int i = 0; i < m; ++i)
                matrix[i][Y] = 0;
        }
    }
