// 单调栈思路,这里使用双端队列,好操作
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> dq;
        int l=0;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty()&&nums[i]<dq.back()&&l<(nums.size()-k)){
                dq.pop_back();
                l++;
            }
            dq.push_back(nums[i]);
        }
        while(!dq.empty()&&k--){
            v.push_back(dq.front());dq.pop_front();
        }
        return v;
    }
};