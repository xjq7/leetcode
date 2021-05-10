class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<m*k)return -1;
        int maxDay=INT_MIN,minDay=INT_MAX;
        for(int val:bloomDay){
            maxDay=max(maxDay,val);
            minDay=min(minDay,val);
        }
        int left=minDay,right=maxDay;
        while(left<right){
            int mid=(left+right)/2;
            int t=0,blooms=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    t++;
                }else{
                    blooms+=t/k;
                    t=0;
                }
                
            }
            blooms+=t/k;
            if(blooms>=m){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};