void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            while (flag<m+i && nums2[i] > nums1[flag]) 
                ++flag;
            nums1.insert(nums1.begin() + flag++, nums2[i]);
            nums1.erase(nums1.end()-1);
        }
    }
