class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> combine;
        backTrack(ret,candidates,combine,target,0);
        return ret;
    }

    void backTrack(vector<vector<int>>& ret,vector<int>& candidates,vector<int>& combine,int target,int idx){
        if(idx==candidates.size()){
            return;
        }
        if(target==0){
            ret.emplace_back(combine);
            return;
        }
        if(target>0){
            for(int i=idx;i<candidates.size();i++){
                combine.push_back(candidates[i]);
                backTrack(ret,candidates,combine,target-candidates[i],i);
                combine.pop_back();
            }
        }
    }
};