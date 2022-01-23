//给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
//丑数 就是只包含质因数 2、3 和/或 5 的正整数。
bool isUgly(int n) {
        if(n<=0)
            return false;
        while(n%2==0)
            n=n>>1;
        while(n%3==0)
            n=n/3;
        while(n%5==0)
            n=n/5;
        return n==1;
    }
