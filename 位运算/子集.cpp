class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int size = nums.size();
        for(int i=0;i<(1<<size);i++){
            vector<int> temp;
            for(int j=0;j<size;j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};