class Solution {
public:
    string sortString(string s) {
        int c[26];
        for(int i=0;i<26;i++)c[i]=0;
        for(int i=0;i<s.size();i++)c[s[i]-97]++;

        vector<pair<char,int>> v;
        for(int i=0;i<26;i++){
            if(c[i])v.push_back(pair<char,int>(char(97+i),c[i]));
        }
        string ret;
        while(ret.size()!=s.size()){
            for(int i=0;i<v.size();i++){
                if(v[i].second){
                    ret+=v[i].first;
                    v[i].second--;  
                }
            }
            for(int i=v.size()-1;i>=0;i--){
                if(v[i].second){
                    ret+=v[i].first;
                    v[i].second--;  
                }
            }
        }
        return ret;
    }
};