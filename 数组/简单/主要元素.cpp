class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int>::iterator it;
        for(it=nums.begin();it!=nums.end();it++){
            m[*it]++;
            if(m[*it]>nums.size()/2){
                return *it;
            }
        }
        return -1;
    }
};