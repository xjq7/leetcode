/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
  let res = [],
    track = []
  function backTrack(res, track, nums) {
    if (track.length === nums.length) {
      res.push([...track])
      return
    }
    for (let i = 0; i < nums.length; i++) {
      if (track.find((v) => v === nums[i]) !== undefined) {
        continue
      }
      track.push(nums[i])
      backTrack(res, track, nums)
      track.pop()
    }
  }
  backTrack(res, track, nums)
  return res
}
