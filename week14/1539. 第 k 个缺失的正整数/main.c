class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=arr[0]-1;
        if(num>=k) return k;
        for(int i=1;i<arr.size();++i){
            num=num+arr[i]-arr[i-1]-1;
            if(num>=k) return i+k;
        }
        return arr.size()+k;
    }
};
