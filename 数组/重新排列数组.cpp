class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0,j=n;
        vector<int> ret;
        while(i<n){
            ret.push_back(nums[i]);
            ret.push_back(nums[j]);
            i++;
            j++;
        }
        return ret;
    }
};