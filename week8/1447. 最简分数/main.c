/*给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。*/
vector<string> simplifiedFractions(int n) {
    vector<string>ans;
    for (int i=2;i<=n;++i) {
        for (int j=1;j<i;++j) {
            if (__gcd(j,i)==1) {
                ans.emplace_back(to_string(j)+"/"+to_string(i));
            }
        }
    }
    return ans;
}
