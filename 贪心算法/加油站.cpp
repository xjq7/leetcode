// 直接遍历
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int myGas = 0;
        int i=0,start=-1,cycle=false;
        while(i<gas.size()){
            if(i==start)return start;
            if((myGas+gas[i])>=cost[i]){
                myGas=myGas+gas[i]-cost[i];
                if(start==-1)start=i;
            }else{
                if(cycle){
                    return -1;
                }else{
                    start=-1;
                    myGas=0;
                }
            }
            i++;
            if(i==gas.size()){
                if(start!=-1){
                    i=0;
                    cycle=true;
                }else{
                    return -1;
                }
            }

        }
        return -1;
    }
};