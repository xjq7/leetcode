class Solution {    
    public:
        int deleteAndEarn(vector<int> &nums) {
            int maxVal=1;
            for(int val:nums){
                if(val>maxVal)maxVal=val;
            }
            int sum[maxVal+1];
            for(int i=0;i<=maxVal;i++){
                sum[i]=0;
            }
            for (int val:nums) {
                sum[val]++;
            }
            int dp[maxVal+1];
            dp[0]=sum[0];
            dp[1]=max(sum[0],sum[1]);
            for(int i=2;i<=maxVal;i++){
                dp[i]=max(dp[i-1],sum[i]*i+dp[i-2]);
            }
            return dp[maxVal];
        }
};
