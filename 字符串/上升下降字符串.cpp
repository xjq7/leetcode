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
        int i=-1,f=true;
        int size=v.size();
        while(ret.size()!=s.size()){
            if(i==-1){
                i++;
                f=true;
            }
            if(i==size){
                i--;
                f=false;
            }
            if(v[i].second){
                ret+=v[i].first;
                v[i].second--;  
            }
            if(f){
                i++;
            }else{
                i--;
            }          
        }
        return ret;
    }
};