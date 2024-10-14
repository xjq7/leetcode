/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  let l = 0;
  r = 0;

  let set = new Set();
  let res = 0;

  for (let i = 0; i < s.length; i++) {
    r++;
    if (set.has(s[i])) {
      res = Math.max(res, r - l - 1);
      while (s[l] !== s[i]) {
        set.delete(s[l++]);
      }
      l++;
    } else {
      res = Math.max(res, r - l);
      set.add(s[i]);
    }
  }

  return res;
};
