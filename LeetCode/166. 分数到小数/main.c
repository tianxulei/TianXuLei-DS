/*给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
如果小数部分为循环小数，则将循环的部分括在括号内。
如果存在多个答案，只需返回 任意一个 。
对于所有给定的输入，保证 答案字符串的长度小于 104 。

示例 1：
输入：numerator = 1, denominator = 2
输出："0.5"*/

string fractionToDecimal(int numerator, int denominator) {
        string str = "";
        bool fuhao=false;
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0))
            fuhao=true;
        numerator=abs(numerator);
        denominator=abs(denominator);
        int a = numerator / denominator;//商
        long res = numerator % denominator;//余数
        //整数部分
        if (a == 0)
            str = "0";
        while (a > 0) {
            str = (char)(a % 10+'0') + str;
            a = a / 10;
        }
        //小数点
        if (res != 0) {
            str = str + '.';
            map<long, int>table;
            int flag = 0;
            res = res * 10;
            while (res != 0 && !table.count(res)) {
                table[res] = flag++;
                if (res >= denominator) {
                    str = str + (char)(res / denominator+'0');
                    res = res % denominator;
                }
                else {
                    str = str + '0';
                }
                res = res * 10;
            }
            //有循环
            if (res != 0) {
                int b =table.size()- table[res];
                str.insert(str.size() - b, "(");
                str = str + ')';
            }
        }
        if(fuhao)
            return '-'+str;
        return str;
    }
