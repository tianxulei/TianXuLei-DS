vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans={0,((int)numbers.size()-1)};
        while(true){
            int tmp=numbers[ans[0]]+numbers[ans[1]];
            if(tmp==target){
                ans[0]++;
                ans[1]++;
                break;          
            }
            if(tmp<target)
                ++ans[0];
            else 
                --ans[1];
        }
        return ans;
    }
