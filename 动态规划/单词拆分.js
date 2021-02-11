/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    let m={}
    for(let i=0;i<wordDict.length;i++){
        m[wordDict[i]]=true;
    }
    let dp=[];
    dp[0]=true;
    for(let i=1;i<=s.length;i++){
        for(let j=i-1;j>=0;j--){
            dp[i]=dp[j]&& m[s.substring(j,i)]!==undefined;
            if(dp[i])break;
        }
    }
    return dp[s.length];
};