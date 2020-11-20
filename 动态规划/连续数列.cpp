class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())return -2147483648;
        if(nums.size()==1)return nums[0];
        int m = nums[0];
        int dp1 = nums[0];
        for(int i=1;i<nums.size();i++){
           dp1=max(nums[i],dp1+nums[i]);
           m=max(dp1,m);
        }
        return m;
    }
};