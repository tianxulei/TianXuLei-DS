//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 
int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;++i){
            int flag=0;
            for(int num:nums){
                flag=flag+((num>>i)&1);
            }
            if(flag%3){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
//按二进制位相加，三个数字每一位结果为三的倍数，%3就能得到出现一次的
