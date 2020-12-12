// 贪心
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

// 动态规划
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size();
        if(size<2)return size;
        vector<int> up(size),down(size);
        up[0]=1;down[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                down[i]=max(up[i-1]+1,down[i-1]);
                up[i]=up[i-1];
            }else if(nums[i]>nums[i-1]){
                up[i]=max(down[i-1]+1,up[i-1]);
                down[i]=down[i-1];
            }else{
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }
        return max(down[size-1],up[size-1]);
    }
};