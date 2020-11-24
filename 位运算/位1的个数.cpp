class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        uint32_t k=1;
        for(int i=0;i<32;i++){
            if(n&k){
                c++;
            }
            k=k<<1;
        }
        return c;
    }
};