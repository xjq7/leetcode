class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())return -2147483648;
        int pre=nums[0];
        int max=pre;
        for(int i=1;i<nums.size();i++){
            int sum = pre+nums[i];
            pre=sum>nums[i]?sum:nums[i];
            if(pre>max)max=pre;
        }
        return max;
    }
};