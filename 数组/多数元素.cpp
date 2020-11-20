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

// 先排序,然后取中间数字
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};