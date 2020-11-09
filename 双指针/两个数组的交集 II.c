/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void quickSort(int* arr,int left,int right){
    if(left>right){
        return ;
    }
    int temp,t;
    temp = arr[left];
    int i = left;
    int j = right;
    while (i!=j) {
        while (i<j&&arr[j]>=temp) {
            j--;
        }
        while (i<j&&arr[i]<=temp) {
            i++;
        }
        if(i<j){
            t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }

    arr[left]=arr[i];
    arr[i]=temp;
    quickSort(arr,left,i-1);
    quickSort(arr,i+1, right);
}


//将相同字段加入新数组
int* mainrun(int* arr1,int nums1Size,int* arr2,int nums2Size,int *returnSize){
    int *res;
    int j=0,i=0,len,index=0;
    len = nums1Size<nums2Size?nums2Size:nums1Size;
    res = (int*)malloc(sizeof(int)*len);
    while(j<nums2Size&&i<nums1Size){
        if(arr1[i]>arr2[j]){
            j++;
        }else if(arr1[i]==arr2[j]){
            res[index++]=arr1[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    printf("%d\n",index);
    *returnSize = index;
    return res;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ret;
    //排序
    quickSort(nums1,0,nums1Size-1);
    quickSort(nums2,0,nums2Size-1);

    //运行主函数,拿到结果
    ret = mainrun(nums1,nums1Size,nums2,nums2Size,returnSize);
    return ret;
}