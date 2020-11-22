class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end(),[&](vector<int> &a,vector<int> &b){return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);});
        int m=1,pre=points[0][0],end=points[0][1];
        for(int i=1;i<points.size();i++){
            int curPre = points[i][0],curEnd=points[i][1];
            if(curPre>end){
                pre=curPre;
                end=curEnd;
                m+=1;
            }else{
                if(curPre>pre){
                    pre=curPre;
                }
                if(curEnd<end){
                    end=curEnd;
                }
            }
        }
        return m;
    }
};