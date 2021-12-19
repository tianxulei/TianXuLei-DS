class Solution {
public:
    int numSquares(int n) {
        //动态规划法
	/*	vector<int>nums(n + 1);
	int a = sqrt(n);
	int b = 1;
	for (int i = 1; i <= a; ++i)
	{
		nums[b] = 1;
		b = b + 1 + (i << 1);
	}
	for (int i = 2; i < n + 1; ++i)
	{
		if (nums[i] != 1)
		{
			int min = 4;
			for (int j = 1; j <= i >>1; ++j)
			{
				int k = nums[j] + nums[i - j];
				if (k < min)
					min = k;
			}
			nums[i] = min;
		}
	}
	cout << nums[n];*/

	if ((int)sqrt(n) == sqrt(n))
		return 1;

	while (n % 4 == 0)
		n /= 4;

	if (n % 8 == 7)
		return 4;

	for (int i = 1; i <= sqrt(n); ++i)
		if ((int)sqrt(n - i * i) == sqrt(n - i * i))
			return 2;
	return 3;
    }
};
