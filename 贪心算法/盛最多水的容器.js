/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let i = 0,
    j = height.length - 1;

  let res = 0;

  while (i < j) {
    res = Math.max(Math.min(height[i], height[j]) * (j - i), res);
    if (height[i] > height[j]) {
      j--;
    } else {
      i++;
    }
  }
  return res;
};
