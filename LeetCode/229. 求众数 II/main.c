/*给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

示例 1：
输入：[3,2,3]
输出：[3]*/
vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0, numa = 0, numb = 0;
        for (auto num : nums) {
            if (numa == 0 && num != b) {
                a = num;
                numa++;
            }
            else if (numb == 0 && num != a) {
                b = num;
                numb++;
            }
            else {
                if (num == a)
                    numa++;
                else if (num == b)
                    numb++;
                else {
                    numa--;
                    numb--;
                }
            }
        }

        int na = 0, nb = 0;
        for (auto num : nums) {
            if (num == a)
                na++;
            else if (num == b)
                nb++;
        }
        vector<int>ans;
        if (na > nums.size() / 3)
            ans.push_back(a);
        if (nb > nums.size() / 3)
            ans.push_back(b);
        return ans;
    }
