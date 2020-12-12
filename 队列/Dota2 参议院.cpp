class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int n=senate.size();
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                q1.push(i);
            }else{
                q2.push(i);
            }
        }

        while(!q1.empty()&&!q2.empty()){
            if(q1.front()<q2.front()){
                q1.push(q1.front()+n);
            }else{
                q2.push(q2.front()+n);
            }
            q1.pop();
            q2.pop();
        }
        return q1.empty()?"Dire":"Radiant";
    }
};