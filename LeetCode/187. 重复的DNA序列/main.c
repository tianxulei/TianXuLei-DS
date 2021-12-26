vector<string> findRepeatedDnaSequences(string s) {
        map<char, int>DNA = { {'A',0},{'C',1},{'G',2} ,{'T',3} };
        vector<string>ans;
        if (s.size() <= 10)
		    return ans;
        map<int, int>nums;
        int a = 0;
        for (int i = 0; i < 10; ++i)
            a = (a << 2) | DNA[s[i]];
        nums[a] = nums[a] + 1;
        for (int i = 1; i < s.size() - 9; ++i)
        {
            a = ((a << 2) | DNA[s[i + 9]]) & ((1 << 20) - 1);
            if (nums[a] == 1)
                ans.push_back(s.substr(i, 10));
            nums[a] = nums[a] + 1;
        }
        return ans;
    }
