//  哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        map<int,int>::iterator it;
        int maxTime=0,maxNum=0;
        for(it=m.begin();it!=m.end();it++){
            if((*it).second>maxTime){
                maxNum=(*it).first;
                maxTime=(*it).second;
            }
        }
        return maxNum;
    }
};