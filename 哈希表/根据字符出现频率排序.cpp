class Solution {
public:
    string frequencySort(string s) {
        pair<char,int> c[123];
        for(int i=0;i<123;i++)c[i]=pair<char,int>(char(i),0);
        for(int i=0;i<s.size();i++)c[s[i]].second++;
        sort(c,c+123,[](pair<char,int> a, pair<char,int> b){return a.second>b.second;});
        string ret;
        for(int i=0;i<123;i++){
            while(c[i].second){
                ret+=c[i].first;
                c[i].second--;
            }
        }
        return ret;
    }
};