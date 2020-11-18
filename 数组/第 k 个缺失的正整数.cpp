class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int pre=0;
        for(int i=0;i<arr.size();i++){
            int diff = arr[i]-pre;
            if(diff>1){
                if(diff-1>=k){
                    return pre+k;
                }else{
                    k-=diff-1;
                } 
            }
            pre=arr[i];
        }
        return arr[arr.size()-1]+k;
    }
};