/**
 * @param {number[]} nums
 * @return {number[][]}
 */

//  排序后双指针
var threeSum = function(nums) {
    nums.sort((a,b)=>a-b);
    let n=nums.length;
    let res=[];
    if(n<3)return res;
    for(let i=0;i<n;i++){
        if(nums[i]>0)return res;
        if(i>0&&nums[i]===nums[i-1]){
            continue;
        }
        let l=i+1;
        let r=n-1;
        while(l<r){
            if(nums[i]+nums[l]+nums[r]==0){ 
                res.push([nums[i],nums[l],nums[r]]);
                while(l<r&&nums[l]==nums[l+1]){
                    l++;
                }
                while(l<r&&nums[r]==nums[r-1]){
                    r--;
                }
                l++;
                r--;
            }else if(nums[i]+nums[l]+nums[r]>0){
                r--;
            }else{
                l++;
            }
        }
    }
    return res;
};