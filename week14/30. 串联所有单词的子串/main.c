class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        set<string>st;
        map<string,int>mp;
        for(auto word:words){
            st.insert(word);
            mp[word]++;
        } 
        int size=words[0].size();
        vector<int>ans;
        for(int i=0;i<s.size()-words.size()*size+1;++i){
            if(st.count(s.substr(i,size)) && s.size()-i+1>=words.size()*size){
                map<string,int>tmp(mp);
                for(int j=0;j<words.size();++j){
                    if(tmp.count(s.substr(i+j*size,size))){
                        tmp[(s.substr(i+j*size,size))]--; 
                        if(tmp[(s.substr(i+j*size,size))]==0)
                            tmp.erase((s.substr(i+j*size,size)));
                    }
                    else break;
                }
                if(tmp.empty()) ans.push_back(i);
            }
        }
        return ans;
    }
};
