/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function (A) {
  let len = A.length;
  let n = 0;
  let ret = [];
  for (let i = 0; i < len; i++) {
    n = n << 1;
    n += 1 * A[i];
    ret.push(n % 5 === 0);
    n %= 5;
  }
  return ret;
};
