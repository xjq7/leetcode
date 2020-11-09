/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int * ret = (int*)malloc(sizeof(int)*2);
    int i=0,j=numsSize-1;
    *returnSize=2;
    ret[0]=-1;
    ret[1]=-1;
    while(i<=j){
        if(nums[i]==target){
            ret[0]=i;
            while((i<numsSize-1)&&(nums[i+1]==target))i++;
            ret[1]=i;
            return ret;
        }else{
            i++;
        }
        if(nums[j]==target){
            ret[1]=j;
            while((j>0)&&(nums[j-1]==target))j--;
            ret[0]=j;
            return ret;
        }else{
            j--;
        }
    }
    return ret;
}