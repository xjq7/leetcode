class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2)return;
        k%=nums.size();
        vector<int> temp;
        int i=nums.size()-1,j=k;
        while(j--){
            temp.push_back(nums[i--]);
        }
        for(int i=nums.size()-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        for(int i=temp.size()-1;i>=0;i--){
            nums[k-i-1]=temp[i];
        }
    }
};