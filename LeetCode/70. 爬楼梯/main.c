int climbStairs(int n) {
        if (n < 3) return n;
        vector<int>a{ 1,2 };
        for (int i = 2; i < n; ++i) {
            a.push_back(a[0] + a[1]);
            a.erase(a.begin());
        }
        return a.back();
    }
    //动态规划,每次只能爬两阶，所以该层的值取决于前两层
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
