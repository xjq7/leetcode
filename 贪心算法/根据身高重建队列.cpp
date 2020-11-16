class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int>&x,vector<int>&y)->bool{return x[0]>y[0]||(x[0]==y[0]&&x[1]<y[1]);});
        for(int i=1;i<people.size();i++){
            int count=people[i][1];
            for(int j=0;j<i;j++){
                if(count){
                    count--;
                }else{
                    vector<int> temp=people[i];
                    people.erase(people.begin()+i);
                    people.insert(people.begin()+j,temp);
                    break;
                }
            }
        }
        return people;
    }
};