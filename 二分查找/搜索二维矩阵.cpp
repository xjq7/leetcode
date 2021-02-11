class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }else{
            if(matrix[0].size()==0){
                return false;
            }
        }
        int m=matrix.size(),n=matrix[0].size();
        int start=0,end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int i=mid/n,j=mid%n;
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
};