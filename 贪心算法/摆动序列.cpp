class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        int diff=nums[1]-nums[0];
        int ret=diff!=0?2:1;
        for(int i=2;i<nums.size();i++){
            int curDiff = nums[i]-nums[i-1];
            if((curDiff>0&&diff<=0)||(curDiff<0&&diff>=0)){
                ret++;
                diff=curDiff;
            }
        }
        return ret;
    }
};