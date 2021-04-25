function maxSumSubmatrix(matrix: number[][], k: number): number {
  const y = matrix.length, x = matrix[0].length;
  const sum = new Array(y + 1);
  for (let i = 0; i <= y; i++)sum[i] = new Array(x + 1);
  let max = -Infinity;
  for (let i = 1; i <= x; i++) {
    for (let j = 1; j <= y; j++) {
      sum[j][i] = matrix[j - 1][i - 1] + (sum[j][i - 1] || 0) + (sum[j - 1][i] || 0) - (sum[j - 1][i - 1] || 0);
    }
  }
  for (let i = 1; i <= x; i++) {
    for (let j = 1; j <= y; j++) {
      for (let p = i; p <= x; p++) {
        for (let q = j; q <= y; q++) {
          let cur = sum[q][p] - (sum[q][i - 1] || 0) - (sum[j - 1][p] || 0) + (sum[j - 1][i - 1] || 0);
          if (cur > max && cur <= k) max = cur;
        }
      }
    }
  }
  return max;
};