int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tmp = 0;
        int flag = 0;
        for (int i = 0; i < gas.size(); ++i)
            tmp += gas[i] - cost[i];
        if (tmp >= 0)
        {
            tmp = 0;
            for (int i = 0; i < gas.size(); ++i)
            {
                tmp += gas[i] - cost[i];
                if (tmp < 0)
                {
                    tmp = 0;
                    flag = i + 1;
                }
            }
            return flag;
        }
        return -1;
    }
