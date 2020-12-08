class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backTrack(res,track,nums);
        return res;
    }

    void backTrack(vector<vector<int>> &res,vector<int> &track,vector<int> &nums){
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!(find(track.begin(), track.end(), nums[i]) == track.end())){
                continue;
            }
            track.push_back(nums[i]);
            backTrack(res,track,nums);
            track.pop_back();
        }
    }
};