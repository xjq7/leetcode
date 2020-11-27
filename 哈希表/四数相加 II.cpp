class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int k=0;
        map<int,int> m;
        for(int v1:A){
            for(int v2:B){
                m[v1+v2]++;
            }
        }
        map<int,int>::iterator it;
        for(int v3:C){
            for(int v4:D){
                if(m[-(v3+v4)]){
                    k+=m[-(v3+v4)];
                }
            }
        }
        return k;
    }
};
