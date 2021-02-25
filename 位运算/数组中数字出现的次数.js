/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumbers = function (nums) {
  let n = 0
  nums.forEach((num) => {
    n ^= num
  })
  let k = 1
  while ((k & n) === 0) {
    k <<= 1
  }
  let a = 0,
    b = 0
  nums.forEach((num) => {
    if (num & k) {
      a ^= num
    } else {
      b ^= num
    }
  })
  return [a, b]
}
