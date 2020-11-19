class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        while(i<nums.size()&&j<nums.size()){
            if(nums[i]==0&&nums[j]==0){
                j++;
            }else if(nums[i]==0&&nums[j]!=0){
                nums[i]=nums[j];
                nums[j]=0;
                i++;
                j++;
            }else if(nums[i]!=0&&nums[j]==0){
                i++;
                j++;
            }else{
                i+=2;
                j+=2;
            }
        }
    }
};