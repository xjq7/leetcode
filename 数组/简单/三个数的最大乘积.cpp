class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int max1=nums[len-1]*nums[len-2]*nums[len-3];
        int max2=nums[0]*nums[1]*nums[len-1];
        if(nums[0]<0&&nums[1]<0){
            return max(max1,max2);
        }else{
            return max1;
        }
    }
};