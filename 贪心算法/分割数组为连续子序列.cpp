class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        for(int v:nums){
            m1[v]++;
        }
        for(int x:nums){
           int count = m1[x];
            if (count > 0) {
                int prevEndCount = m2[x - 1];
                if (prevEndCount > 0) {
                    m1[x] = count - 1;
                    m2[x - 1]--;
                    m2[x]++;
                } else {
                    int count1 = m1[x + 1];
                    int count2 = m1[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        m1[x]--;
                        m1[x + 1]--;
                        m1[x + 2]--;
                        m2[x + 2]++;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};