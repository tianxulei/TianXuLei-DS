class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size());
        vector<int>stuck;
        for (int i = 0; i < temperatures.size(); ++i)
        {
            if (stuck.size() == 0 || temperatures[i] <= temperatures[stuck.back()])
                stuck.push_back(i);
            else
            {
                while (!stuck.empty() && temperatures[i] > temperatures[stuck.back()])
                {
                    result[stuck.back()] = i - stuck.back();
                    stuck.pop_back();
                }
                stuck.push_back(i);
            }
        }
        return result;
    }
};
