class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k=nums.size();
        for(int i=0;i<nums.size();i++){
            k^=i^nums[i];
        }   
        return k;
    }
};