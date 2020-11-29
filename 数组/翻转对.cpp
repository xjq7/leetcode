//  归并
class Solution {
public:
    void mergeSort(vector<int> &arr,int start,int end,vector<int> &temp, int &count){
        if(start<end){
            int mid=start+(end-start)/2;
            mergeSort(arr,start,mid,temp,count);
            mergeSort(arr,mid+1,end,temp,count);
            merge(arr,start,mid,end,temp,count);
        }
    }
    void merge(vector<int> &nums,int start,int mid,int end,vector<int> &temp,int &count){
        int i=start;
        int j=mid+1;
        while(i<=mid&&j<=end){
            if((long long) nums[i]>(long long)2*nums[j]){
                count+=mid-i+1;
                j++;
            }else{
                i++;
            }
        }

        i=start,j=mid+1;
        int k=0;
        while(i<=mid&&j<=end){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }

        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=end){
            temp[k++]=nums[j++];
        }
        for(int i=0;i<k;i++){
            nums[start+i]=temp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        int count=0;
        vector<int> temp(nums.size(),0);
        mergeSort(nums,0,nums.size()-1,temp,count);
        return count;
    }
};