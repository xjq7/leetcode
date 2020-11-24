class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int v:nums){
            v=abs(v);
            if(nums[v-1]<0){
                ret.push_back(v);
            }else{
                nums[v-1]=-nums[v-1];
            }
        }
        return ret;

    }
};