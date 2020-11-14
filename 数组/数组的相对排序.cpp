class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret;
        map<int,int> m;
        for(int v1:arr1){
            m[v1]++;    
        }
        for(int v2:arr2){
            while(m[v2]--){
                ret.push_back(v2);
            }  
        }        

        map<int,int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){
            if(iter->second>0){
                while(iter->second--){
                    ret.push_back(iter->first);    
                }
            }
        }
        return ret;
    }
};