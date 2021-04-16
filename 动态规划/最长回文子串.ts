function longestPalindrome(s: string): string {
  const n=s.length;
  const dp:boolean[][]=[];
  for(let i=0;i<n;i++){
      dp[i]=new Array(n);
  }   
  let maxLen=1,maxIndex=0;
  for(let j=1;j<n;j++){
      for(let i=0;i<j;i++){
          if(s[i]===s[j]){
              if(j-i<3){
                  dp[i][j]=true;
              }else{
                  dp[i][j]=dp[i+1][j-1];
              }
          }else{
              dp[i][j]=false;
          }
          if(dp[i][j]&&(j-i+1)>maxLen){
              maxLen=j-i+1;
              maxIndex=i;
          }
      }
      
  }

  return s.substring(maxIndex,maxLen+maxIndex);
};