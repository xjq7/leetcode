class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N==0)return 0;
        vector<int> v;
        while(N){
            v.push_back(N%10);
            N/=10;
        }
        deque<int> q;
        q.push_back(v[v.size()-1]);
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]>=q.back()){
                q.push_back(v[i]);
            }else{    
                int prev=q.back();
                q.pop_back();
                int count=0;
                while(!q.empty()&&prev==q.back()){
                    q.pop_back();
                    count++;
                }
                q.push_back(prev-1);
                for(int j=count+i;j>=0;j--){
                    q.push_back(9);
                }
                break;
            }
        }
        int sum=0;
        while(!q.empty()){
            sum*=10;
            sum+=q.front();
            q.pop_front();
        }
        return sum;
    }
};