//计算柱状图的最大矩形面积（参考84题）
    int largestRectangleArea(vector<int> heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int ans = 0, size = heights.size();
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int tmp = st.top();
                st.pop();
                ans = max(ans, heights[tmp] * (i - st.top() - 1));
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //定义一个柱状图
        vector<int>dp(matrix[0].size(),0);
        int ans=0;
        //矩阵长和宽
        int m=matrix.size(),n=matrix[0].size();
        //生成每一行的柱状图并计算面积
        for(int i=0;i<m;++i){
            //更新这一行的柱状图
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='1') ++dp[j];
                else dp[j]=0;
            }
            //计算柱状图的最大矩形面积并更新最大面积
            ans=max(ans,largestRectangleArea(dp));
        }
        return ans;
    }
