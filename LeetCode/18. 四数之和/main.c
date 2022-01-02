vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 3; ++i) {//第一重循环,i指向第一个数
            if ((i > 0 && nums[i] != nums[i - 1]) || i == 0) {//去重,遇到和上一个相同的nums[i],就跳过
                for (int j = i + 1; j < size - 2; ++j) {//第二重循环,j指向第二个数
                    if ((j > i + 1 && nums[j] != nums[j - 1]) || j == i + 1) {//去重,遇到和上一个相同的nums[j],就跳过
                        //第三重循环,a,b指向j后面的第一个和最后一个元素,向中间靠拢
                        long long tmp = nums[i] + nums[j], a = j + 1, b = size - 1;
                        while (a < b) {
                            if (tmp + nums[a] + nums[b] > target) {
                                --b;
                                while (b>a && nums[b] == nums[b + 1])
                                    --b;
                            }
                            else if (tmp + nums[a] + nums[b] < target) {
                                ++a;
                                while (a<b && nums[a] == nums[a - 1])
                                    ++a;
                            }
                            else {
                                ans.push_back(*(new vector<int>{ nums[i], nums[j], nums[a++], nums[b--] }));
                                while (b > a && nums[b] == nums[b + 1])
                                    --b;
                                while (a < b && nums[a] == nums[a - 1])
                                    ++a;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
