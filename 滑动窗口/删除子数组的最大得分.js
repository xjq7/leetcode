/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function (nums) {
  let start = 0,
    sum = 0,
    max = 0;
  let m = {};
  for (let i = 0; i < nums.length; i++) {
    if (!m[nums[i]]) {
      sum += nums[i];
      m[nums[i]] = true;
      if (sum > max) max = sum;
    } else {
      while (nums[i] != nums[start]) {
        m[nums[start]] = false;
        sum -= nums[start];
        start++;
      }
      start++;
    }
  }
  return max;
};
