class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string ret;
        if(num.size()==k)return "0";
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!s.empty()&&num[i]<s.top()&&k){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }    
        while(k--){
            s.pop();
        }
        while(!s.empty()){
            ret =  s.top()+ret;
            s.pop();
        }
        while(ret.size()>1&&ret[0]=='0'){
            ret.erase(0,1);
        }

        return ret;
    }
};