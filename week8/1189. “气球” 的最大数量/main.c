/*给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
示例 1：
输入：text = "nlaebolko"
输出：1
示例 2：
输入：text = "loonbalxballpoon"
输出：2*/
int maxNumberOfBalloons(string text) {
        vector<double>table(5,0);
        for(int i=0;i<text.size();++i){
            if(text[i]=='b') table[0]++;
            else if(text[i]=='a') table[1]++;
            else if(text[i]=='l') table[2]+=0.5;
            else if(text[i]=='o') table[3]+=0.5;
            else if(text[i]=='n') table[4]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<5;++i)
            ans=min(ans,(int)table[i]);
        return ans;
    }
