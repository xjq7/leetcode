class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        for(int i=0;i<A.size();i++){
            ans[i]=pow(A[i],2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};