int trap(vector<int>& height) {
        int size = height.size();
        vector<int> l(size,0);
        vector<int> r(size,0);
        int max = height.front();
        for (int i = 1; i < size; ++i) {
            if (l[i] < max) l[i] = max;
            if (height[i] > max) max = height[i];
        }
        max = height.back();
        for (int i = size - 2; i >= 0; --i) {
            if (r[i] < max) r[i] = max;
            if (height[i] > max) max = height[i];
        }
        int result = 0;
        for (int i = 1; i <= size - 2; ++i) 
            if (height[i] < min(l[i], r[i])) result += min(l[i], r[i]) - height[i];
        return result;
    }
