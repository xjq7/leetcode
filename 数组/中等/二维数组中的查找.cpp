class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0|| matrix[0].size()==0){return false;}
        int i=matrix[0].size()-1;
        int rows = matrix.size();
        int row=0;
        while(row<rows&&i>=0){
            int cur = matrix[row][i];
            if(cur>target){
                i--;
            }else if(cur==target){
                return true;
            }else{
                row++;
            }
        }
        return false;
    }
};