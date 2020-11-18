class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            v.push_back(arr[i]);
        }
        map<int,int> m;
        sort(v.begin(),v.end());
        int i=1,j=0;
        while(j<v.size()){
            if(!m[v[j]]){
                m[v[j]]=i;
                i++;
            }
            j++;
        }
        for(int i=0;i<v.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};