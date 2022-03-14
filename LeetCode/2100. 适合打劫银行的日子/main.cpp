/*你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。
如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：
第 i 天前和后都分别至少有 time 天。
第 i 天前连续 time 天警卫数目都是非递增的。
第 i 天后连续 time 天警卫数目都是非递减的。
更正式的，第 i 天是一个合适打劫银行的日子当且仅当：security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
请你返回一个数组，包含 所有 适合打劫银行的日子（下标从 0 开始）。返回的日子可以 任意 顺序排列。*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int size=security.size(),flag=1;
        vector<int>preday(size,1),nextday(size,1);
        for(int i=1;i<size-time;++i)
            if(security[i]<=security[i-1]) preday[i]=++flag;
            else flag=1;
        flag=1;
        for(int i=size-2;i>=0+time;--i)
            if(security[i]<=security[i+1]) nextday[i]=++flag;
            else flag=1;
        vector<int>ans;
        for(int i=time;i<size-time;++i)
            if(preday[i]>time && nextday[i]>time)
                ans.push_back(i);
        return ans;
    }
};
