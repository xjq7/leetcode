int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * ret = (int*)malloc(sizeof(int)*nums1Size);
    
    int * stack = (int*)malloc(sizeof(int)*nums2Size);
    
    int * hashMap = (int*)malloc(sizeof(int)*10000);
    int top=-1;
    for(int i=0;i<nums2Size;i++){
        while(top!=-1&&nums2[i]>stack[top]){
            hashMap[stack[top--]] = nums2[i];
        }
        stack[++top]=nums2[i];
    }
    
    while (top>-1) {
        hashMap[stack[top--]]=-1;
    }
    for(int i=0;i<nums1Size;i++){
        ret[i]=hashMap[nums1[i]];
    }
    free(stack);
    free(hashMap);
    *returnSize = nums1Size;
    return ret;
}