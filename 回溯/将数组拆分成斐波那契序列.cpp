class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        backTrack(res,S,0,0,0);
        return res;
    }

    bool backTrack(vector<int> &res,string &S,long long sum,int idx,int prev){
        if(idx==S.size()){
            return res.size()>=3;
        }
        long long cur=0;
        for(int i=idx;i<S.size();i++){
            if(i>idx&&S[idx]=='0')break;
            cur=cur*10+S[i]-'0';
            if(cur>INT_MAX)break;
            if(res.size()>=2){
                if(cur>sum){
                    break;
                }else if(cur<sum){
                    continue;
                }
            }
            res.push_back(cur);
            if(backTrack(res,S,cur+prev,i+1,cur)){
                return true;
            }
            res.pop_back();
        }
        return false;
    }
};