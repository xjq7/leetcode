// O(n)解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v((nums1.size()+nums2.size()));
        int i=0,j=0;
        int k=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                v[k++]=nums1[i++];
            }else{
                v[k++]=nums2[j++];
            }
        }

        while(i<nums1.size()){
            v[k++]=nums1[i++];
        }
        while(j<nums2.size()){
            v[k++]=nums2[j++];
        }

        double res=0;
        int mid=v.size()/2;
        if(v.size()%2==0){
            res=double((v[mid-1]+v[mid]))/2;
        }else{
            res=v[mid];
        }
        return res;
    }
};