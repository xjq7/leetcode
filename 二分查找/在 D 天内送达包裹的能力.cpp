class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int max=0,sum=0;
        for(int val:weights){
            if(val>max)max=val;
            sum+=val;
        }

        while(max<sum){
            int mid=(sum+max)/2;
            int curDay = calDays(weights,mid);
            if(curDay>D){
                max=mid+1;
            }else if(curDay<=D){
                sum=mid;
            }
        }
        return max;
    }

    int calDays(vector<int>& weights,int weight){
        int D=0;
        int sum=0;
        for(int val:weights){
            if((sum+val)>weight){
                D++;
                sum=val;
            }else if((sum+val)==weight){
                D++;
                sum=0;
            }else{
                sum+=val;
            }
        }
        if(sum!=0)D++;
        return D;
    }
};