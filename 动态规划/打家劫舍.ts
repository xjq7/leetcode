function rob(nums: number[]): number {
  const dp:number[]=[];
  dp[0]=nums[0];
  dp[1]=Math.max(nums[0],nums[1]);
  if(nums.length===1)return dp[0];
  if(nums.length===2)return dp[1];
  for(let i=2;i<nums.length;i++){
      dp[i]=Math.max(dp[i-2]+nums[i],dp[i-1]);
  }
  return dp[dp.length-1];
};