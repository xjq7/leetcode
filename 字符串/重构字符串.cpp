class Solution {
public:
    string reorganizeString(string S) {
        int c[26];
        for(int i=0;i<26;i++)c[i]=0;
        for(int i=0;i<S.size();i++)c[S[i]-97]++;
        vector<pair<char,int>> v;
        for(int i=0;i<26;i++){
            if(c[i])v.push_back(pair<char,int>(char(i+97),c[i]));
        }
        sort(v.begin(),v.end(),[&](pair<char,int> &a,pair<char,int> &b){return a.second>b.second;});
        string ret;
        int half = S.size()%2==1?S.size()/2+1:S.size()/2;
        if(v[0].second>half)return "";
        int i=0,j=0;
        while(j<S.size()){
            if(!v[i].second)i++;
            S[j]=v[i].first;
            v[i].second--;
            j+=2;
        }
        j=1;
        while(j<S.size()){
            if(!v[i].second)i++;
            S[j]=v[i].first;
            v[i].second--;
            j+=2;
        }
        return S;
    }
};