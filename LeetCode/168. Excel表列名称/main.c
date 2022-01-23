/*给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 */

string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber!=0){
            --columnNumber;
            char a=columnNumber%26+'A';
            str= a+str;
            columnNumber/=26;
        }
        return str;
    }
