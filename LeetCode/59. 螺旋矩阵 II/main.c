vector<vector<int>> generateMatrix(int n) {
        
        //定义方向和各方向的终点
        int direction = 0;
        vector<int>dircetions{ n - 1,n - 1,0,1 };

        //申请返回数组空间
        vector<vector<int>>ans;
        int a=n;
        while (a--) ans.push_back(vector<int>(n));

        int M = 0, N = -1, flag = 0;

        for (int i = 0; i < (n << 2) - 1; ++i) {
            switch (direction)
            {
            case 0:
                while (N < dircetions[direction]) ans[M][++N] = ++flag;
                dircetions[direction]--;
                direction = (direction + 1) % 4;
                break;
            case 1:
                while (M < dircetions[direction]) ans[++M][N] = ++flag;
                dircetions[direction]--;
                direction = (direction + 1) % 4;
                break;
            case 2:
                while (N > dircetions[direction]) ans[M][--N] = ++flag;
                dircetions[direction]++;
                direction = (direction + 1) % 4;
                break;
            case 3:
                while (M > dircetions[direction]) ans[--M][N] = ++flag;
                dircetions[direction]++;
                direction = (direction + 1) % 4;
                break;
            default:
                break;
            }
        }
        return ans;
    }
