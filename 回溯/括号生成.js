/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
  const ans = [];

  const store = [n, n];

  const dfs = (tmp) => {
    if (!store[0] && !store[1]) {
      ans.push(tmp);
      return;
    }

    if (store[0]) {
      store[0]--;
      dfs(tmp + '(');
      store[0]++;
    }

    if (store[0] < store[1]) {
      store[1]--;
      dfs(tmp + ')');
      store[1]++;
    }
  };
  dfs('');
  return ans;
};
