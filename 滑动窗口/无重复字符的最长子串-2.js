/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  const n = s.length;
  let dp = new Array(n);

  for (let i = 0; i < n; i++) {
    dp[i] = new Array(n).fill(false);
  }

  let start = 0,
    end = 0;

  for (let j = 1; j < n; j++) {
    for (let i = 0; i < j; i++) {
      if (s[i] === s[j]) {
        if (j - i < 3) {
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j] && j - i > end - start) {
          start = i;
          end = j;
        }
      }
    }
  }

  return s.substring(start, end + 1);
};
