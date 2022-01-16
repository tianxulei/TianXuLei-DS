int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        //在最前面和最后面加一个0用于边界计算
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int ans = 0,size = heights.size();
        for (int i = 0; i < size; ++i) {
            //如果当前值大于栈顶，不停地出栈直到不大于
            while (!st.empty() && heights[st.top()] > heights[i]) {
                //取出栈顶元素
                int tmp = st.top();
                st.pop();
                //计算以该栈顶元素为高的矩形，矩形的底为左边，右边不小于栈顶元素的距离
                ans = max(ans, heights[tmp] * (i - st.top() - 1));
            }
            st.push(i);
        }
        return ans;
    }
    //单调递增栈
