class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> stack;
	while (!tokens.empty())
	{
		string str = tokens.front();
		tokens.erase(tokens.begin());

		if (str != "+" && str != "-" && str != "*" && str != "/")
			stack.push(stoi(str));
		else
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (str == "+")
				stack.push(b + a);
			else if (str == "-")
				stack.push(b - a);
			else if (str == "*")
				stack.push(b * a);
			else if (str == "/")
				stack.push((int)(b / a));
        }
	}
	return stack.top();
    }
};
