function rob(nums: number[]): number {
  if(nums.length===1)return nums[0];
  if(nums.length===2)return Math.max(nums[0],nums[1]);
  const dp1:number[]=robRange(nums,0,nums.length-1);
  const dp2:number[]=robRange(nums,1,nums.length);
  return Math.max(dp1[dp1.length-1],dp2[dp2.length-1]);
};

function robRange(nums:number[],start:number,end:number):number[]{
  const dp:number[]=[];
  dp[start]=nums[start];
  dp[start+1]=Math.max(nums[start],nums[start+1]);
  for(let i=start+2;i<end;i++){
      dp[i]=Math.max(nums[i]+dp[i-2],dp[i-1]);
  }
  return dp;
}