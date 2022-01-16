给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。


int maxProfit(vector<int>& prices) {
        int size=prices.size();
        for(int i=size-1;i>0;--i){
            prices[i]=prices[i]-prices[i-1];
        }
        prices[0]=0;
        int Max=0,tmp=0;
        for(int i=1;i<size;++i){
            tmp=tmp+prices[i];;
            if(tmp<0)
                tmp=0;
            Max=max(Max,tmp);
        }
        return Max;
    }
