class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
         int size=tasks.size();
        for(char task:tasks)v[task-'A']++;
        sort(v.begin(),v.end(),[](int x,int y){return x>y;});
        int cnt=1;
        while(cnt<v.size()&&v[cnt]==v[0])cnt++;
        return max(size,(n+1)*(v[0]-1)+cnt);
    }
};