class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> v1,v2;
        vector<int>::iterator it;
        for(it=A.begin();it!=A.end();it++){
            if(*it%2){
                v2.push_back(*it);
            }else{
                v1.push_back(*it);
            }
        }
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;
    }
};