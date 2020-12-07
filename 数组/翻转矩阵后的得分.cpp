class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            if(A[i][0]==0){
                for(int j=0;j<A[i].size();j++){
                    A[i][j]=A[i][j]==0?1:0;
                }
            }
        }

        int w=A[0].size();
        int h=A.size();
        int i=1;
        while(i<w){
            int n=0;
            for(int j=0;j<h;j++){
                if(A[j][i]==0)n++;
            }
            if(n>(h/2)){
                for(int j=0;j<h;j++){
                    A[j][i]=A[j][i]==0?1:0;
                }
            }
            i++;
        }

        int sum=0;
        for(int i=0;i<A.size();i++){
            int temp=0;
            for(int j=A[i].size()-1;j>=0;j--){
                temp+=A[i][j]*pow(2,w-j-1);
            }
            sum+=temp;
        }
        return sum;
    }
};