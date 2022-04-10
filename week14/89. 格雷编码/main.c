class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans(1,0);
        int first=1;
        for(int i=0;i<n;++i){
            for(int j=ans.size()-1;j>=0;--j){
                ans.push_back(first+ans[j]);
            }
            first=first<<1;
        }
        return ans;
    }
};
