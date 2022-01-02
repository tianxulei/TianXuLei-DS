static bool comp(vector<int>& a,vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>>ans;
        int L=intervals[0][0],R=intervals[0][1],size=intervals.size();
        for(int i=1;i<size;++i){
            if(intervals[i][0]<=R){
                R=max(intervals[i][1],R);
            }
            else{
                ans.push_back({L,R});
                L=intervals[i][0];
                R=intervals[i][1];
            }
        }
        ans.push_back({L,R});
        return ans;
    }
