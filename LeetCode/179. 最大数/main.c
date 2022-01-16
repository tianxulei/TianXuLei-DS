给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

//两个字符串互相拼接，看哪个大，哪个就在前面
    static bool comp(const int& a, const int& b) {
        string A = to_string(a), B = to_string(b);
        if (A+B > B+A) return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string result = "";
        for (auto it = nums.begin(); it != nums.end(); ++it) 
            result = result + to_string(*it);
        if (result[0] == '0') return "0";
        return result;
    }
