给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit(vector<int>& prices) {
        //定义一个单调递增栈
        stack<int>st;
        //tmp记录栈底元素值
        int result = 0, tmp = 0;
        //先把第一个元素入栈
        st.push(prices[0]);
        tmp = prices[0];
        for (auto it = prices.begin() + 1; it != prices.end(); ++it) {
            //遇到不小于栈顶元素，入栈
            if (st.top() <= *it)
                st.push(*it);
            else {//否则，计算栈顶和栈底差值，加到结果上
                result += st.top() - tmp;
                //清空栈
                while (!st.empty())
                    st.pop();
                //该元素入栈
                tmp = *it;
                st.push(*it);
            }
        }
        //最后计算一次栈里面剩余的元素
        result += st.top() - tmp;
        return result;
    }
