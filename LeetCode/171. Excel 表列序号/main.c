/*给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回该列名称对应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 */

int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto it=columnTitle.begin();it!=columnTitle.end();++it){
            ans=ans*26-64+*it;
        }
        return ans;
    }
