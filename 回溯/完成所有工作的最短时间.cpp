class Solution {
private:
    int _minTimes=INT_MAX;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> worker(k);
        backTrack(jobs,worker,0,0);
        return _minTimes;
    }
    void backTrack(vector<int>& jobs,vector<int>& worker,int jobIndex,int minTimes){
        if(jobIndex==jobs.size()){
            _minTimes=min(minTimes,_minTimes);
            return;
        }
        for(int i=0;i<worker.size();i++){
            worker[i]+=jobs[jobIndex];
            if(max(worker[i],minTimes)<_minTimes){
                backTrack(jobs,worker,jobIndex+1,max(worker[i],minTimes));
            }
            worker[i]-=jobs[jobIndex];
            if(worker[i] == 0)break;
        }
    }
};