class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]])return true;
            m[nums[i]]=1;
            if(m.size()>k){
                m.erase(nums[i-k]);
            }
        }
        return false;
    }
};