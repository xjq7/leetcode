class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        backTrack(v,s,0,0,n);
        return v;
    }

    void backTrack(vector<string> &v,string &s,int open,int close,int max){
        if(s.size()==max*2){
            v.push_back(s);
            return;
        }
        if(open<max){
            s+='(';
            backTrack(v,s,open+1,close,max);
            s=s.substr(0,s.size()-1);
        }
        if(close<open){
            s+=')';
            backTrack(v,s,open,close+1,max);
            s=s.substr(0,s.size()-1);
        }
    }
};