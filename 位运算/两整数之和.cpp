class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            auto c=((unsigned int)(a&b))<<1;
            a=a^b;
            b=c;
        }
        return a;
    }
};