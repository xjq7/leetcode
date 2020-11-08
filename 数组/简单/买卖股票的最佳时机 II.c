// 贪心
int maxProfit(int* prices, int pricesSize){
    int max_profit=0;
    for(int i=0;i<pricesSize-1;i++)if((prices[i+1]-prices[i])>0)max_profit+=prices[i+1]-prices[i];
    return max_profit;
}