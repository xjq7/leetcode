class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=0;
        for(int v:nums){
            n=v^n;
        }
        return n;
    }
};