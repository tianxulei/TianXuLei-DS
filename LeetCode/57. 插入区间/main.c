vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        	//如果插入的值大于数组最后一个，直接插入最后面
        if (intervals.empty() || newInterval[0] > intervals.back()[1]) {
            intervals.insert(intervals.end(), newInterval);
            return intervals;
        }
        int size = intervals.size();
        for (int i = 0; i < size; ++i) {
            if (newInterval[0] <= intervals[i][1]) {
                //直接插入，无需合并
                if (newInterval[1] < intervals[i][0]) {
                    intervals.insert(intervals.begin() + i, newInterval);
                }
                //需要合并的情况
                else {
                    intervals[i][0] = min(intervals[i][0], newInterval[0]);
                    intervals[i][1] = max(intervals[i][1], newInterval[1]);
                    //循环一直合并直到没有重复区间
                    int tmp = i + 1;
                    while (tmp < size && intervals[tmp][0] <= intervals[i][1]) {
                        ++tmp;
                    }
                    intervals[i][1] = max(intervals[i][1], intervals[tmp - 1][1]);
                    intervals.erase(intervals.begin() + i + 1, intervals.begin() + tmp);
                }
                break;
            }
        }
        return intervals;
    }
