/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  if (!digits.length) return [];
  const keys = [
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
    ['m', 'n', 'o'],
    ['p', 'q', 'r', 's'],
    ['t', 'u', 'v'],
    ['w', 'x', 'y', 'z'],
  ];

  const res = [];
  const tmp = [];

  const dfs = (j) => {
    if (j === digits.length) {
      res.push(tmp.join(''));
      return;
    }

    const index = Number(digits[j]) - 2;
    for (let i = 0; i < keys[index].length; i++) {
      tmp.push(keys[index][i]);
      dfs(j + 1);
      tmp.pop();
    }
  };

  dfs(0, '');

  return res;
};
