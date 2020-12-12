class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>> v;
        for(int i=0;i<aliceValues.size();i++){
            int sum=aliceValues[i]+bobValues[i];
            v.push_back(pair<int,int>(sum,i));
        }
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){return a.first>b.first;});
        int aSum=0,bSum=0;
        for(int i=0;i<v.size();i++){
            if(i%2==0){
                aSum+=aliceValues[v[i].second];
            }else{
                bSum+=bobValues[v[i].second];
            }
        }
        if(aSum==bSum)return 0;
        return aSum>bSum?1:-1;
    }
};