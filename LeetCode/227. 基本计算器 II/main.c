/*给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。

示例 1：
输入：s = "3+2*2"
输出：7*/
int jisuan(char x, int a, int b) {
        if (x == '+') return a + b;
        if (x == '-') return a - b;
        if (x == '*') return a * b;
        return a / b;
    }

    int calculate(string s) {
        stack<char>fuhao;
        stack<int>num;
        for (auto it = s.begin(); it != s.end(); ++it) {
            //除去空格
            if (*it == ' ') continue;
            //是数字
            if (*it - '0' <= 9 && *it - '0' >= 0) {
                int sum = *it - '0';
                ++it;
                while (it != s.end() && (*it - '0' <= 9 && *it - '0' >= 0)) {
                    sum = sum * 10 + (*it - '0');
                    ++it;
                }
                --it;
                num.push(sum);
            }  
            //是符号
            else {
                //如果符号是空的或者碰到优先级大的，就加入
                if (fuhao.empty() || ((*it=='*' || *it=='/') && (fuhao.top()=='+' || fuhao.top() == '-')))
                    fuhao.push(*it);
                else {
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    num.push(jisuan(fuhao.top(), b, a));
                    fuhao.pop();
                    //fuhao.push(*it);
                    --it;
                }
            
            }
        }
        while (!fuhao.empty()) {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(jisuan(fuhao.top(), b, a));
            fuhao.pop();
        }
        return num.top();
    }
