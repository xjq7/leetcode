// 贪心
int maxProfit(int* prices, int pricesSize){
    int min = INT_MAX;
    int max_value=0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<min)min=prices[i];
        max_value=fmax(max_value,prices[i]-min);
    }
    return max_value;
}