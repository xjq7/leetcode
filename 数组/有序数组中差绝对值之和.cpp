// 当前元素小于其他元素时，总和减去当前元素*数组长就是答案
// 另一种情况，当前元素不是最小值，需要处理差值为负数的情况，总和减去当前元素*数组长度之后，将负数相反数的两倍加回来，同时利用前缀和，轻松的求出这个差值

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        vector<int> v(nums.size(),0);
        int prev=0;
        for(int i=0;i<nums.size();i++){
            v[i]=sum-nums[i]*nums.size()+2*(nums[i]*i-prev);
            prev+=nums[i];
        }
        return v;
    }
};