function findMin(nums: number[]): number {
  let i=0,j=nums.length-1;
  let min = Infinity;
  while(i<=j){
    let mid = Math.floor((j-i)/2)+i;
    if(nums[mid]>min){
      if(nums[mid]<nums[j]){
        j=mid-1;
      }else{
        i=mid+1;
      }
    }else{
      min=nums[mid];
      if(nums[mid]<nums[j]){
        j=mid-1;
      }else{
        i=mid+1;
      }
    }
  }
  return min;
};