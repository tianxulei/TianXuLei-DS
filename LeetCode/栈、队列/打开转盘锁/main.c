class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        	//创建锁死元素的哈希表die
	unordered_map<string,bool> die;
	for (vector<string>::iterator it = deadends.begin(); it < deadends.end(); ++it)
		die[*it] = true;

	if (die[target] || die["0000"]) return -1;
    if (target == "0000") return 0;
	//参加过的组合
	unordered_map<string, bool> past;

	int num = 0;//记录次数

	queue<string> all;
	all.push("0000");

	while (!all.empty())
	{
		++num;
		int size = all.size();
		for (int i = 0; i < size; ++i)
		{
			string str = all.front();
			all.pop();
			
			for (int i = 0; i < 4; ++i)
			{
				string str1 = str.substr(0, i) + (str[i] == '9' ? '0' : char(str[i] + 1)) + str.substr(i + 1);
				string str2 = str.substr(0, i) + (str[i] == '0' ? '9' : char(str[i] - 1)) + str.substr(i + 1);
				if (!die[str1])
				{
					if (str1 == target)
						return num;
					if (!past[str1])
					{
						past[str1] = true;
						all.push(str1);
					}
				}
				if (!die[str2])
				{
					if (str2 == target)
						return num;
					if (!past[str2])
					{
						past[str2] = true;
						all.push(str2);
					}
				}
			}
		}
	}
	return -1;
    }
};
