class Solution {
public:
    int waysToStep(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 4;
        unsigned int dp1=1,dp2=2,dp3=4;
        for(int i=4;i<n;i++){
            unsigned int tempDp3 = dp3;
            dp3=(dp1+dp2+dp3)%1000000007;
            dp1=dp2;
            dp2=tempDp3;
        }
        return (dp3+dp2+dp1)%1000000007;
    }
};