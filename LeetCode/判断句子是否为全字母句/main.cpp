/*全字母句 指包含英语字母表中每个字母至少一次的句子。
给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
如果是，返回 true ；否则，返回 false 。*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int ans=0;
        vector<int>tmp(26,0);
        for(auto a:sentence){
            if(tmp[a-'a']==0){
                tmp[a-'a']++;
                ans++;
            }
        }
        return ans==26;
    }
};
