// 归并
class Solution {
public:
    void mergeSort(vector<int> &arr,int first,int last,vector<int> & temp){
        if(first<last){
            int mid=(first+last)/2;
            mergeSort(arr,first,mid,temp);
            mergeSort(arr,mid+1,last,temp);
            merge(arr,first,mid,last,temp);
        }
    }
    void merge(vector<int> &arr,int first,int mid,int last,vector<int> &temp){
        int i=first,j=mid+1;
        int k=0;
        while(i<=mid&&j<=last){
            if(arr[i]>arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=last){
            temp[k++]=arr[j++];
        }
        for(int i=0;i<k;i++){
            arr[i+first]=temp[i];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)return -1;
        vector<int> temp(nums.size(),0);
        mergeSort(nums,0,nums.size()-1,temp);
        return nums[k-1];
    }
};