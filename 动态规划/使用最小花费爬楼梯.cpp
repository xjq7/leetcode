class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int d1=0;
        int d2=0;
        for(int i=0;i<cost.size();i++){
            int curMin = cost[i] +min(d1,d2);
            d1=d2;
            d2=curMin;
        }
        return min(d1,d2);
    }
};