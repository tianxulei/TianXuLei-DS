//给定一个整数 n ，返回 n! 结果中尾随零的数量。
//这里面是数学规律，只要因子含5，就会有0（但不一定是一个25，625）
int trailingZeroes(int n) {
        int ans=0;
        while(n>=5){
            ans+=n/5;
            n=n/5;
        }
        return ans;
    }
