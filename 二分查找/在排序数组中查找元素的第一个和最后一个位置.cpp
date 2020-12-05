class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        if(nums.size()==0)return v;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                int i=mid-1,j=mid+1;
                while(i>=0&&nums[i]==target){
                    i--;
                }
                v[0]=i+1;
                while(j<nums.size()&&nums[j]==target){
                    j++;
                }
                v[1]=j-1; 
                break;
            }
        }
        return v;
    }
};