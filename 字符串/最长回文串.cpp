class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(128,0);
        int len=0;
        for(int c:s){
            if(v[c]%2==1)len+=2;
            v[c]++;
        }
        if(len<s.size())len++;
        return len;
    }
};