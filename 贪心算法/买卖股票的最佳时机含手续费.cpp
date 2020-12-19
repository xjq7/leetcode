class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int max=0,minPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }else if((prices[i]-fee)>minPrice){
                max+=prices[i]-fee-minPrice;
                minPrice=prices[i]-fee;
            }
        }
        return max;
    }
};


