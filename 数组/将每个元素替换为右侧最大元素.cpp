class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int idx=arr.size()-1;
        vector<int> ret;
        ret.push_back(-1);
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i]>arr[idx]){
                idx=i;
                ret.push_back(arr[i]);
            }else{
                ret.push_back(arr[idx]);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};