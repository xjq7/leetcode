/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function (target, n) {
  const push = 'Push',
    pop = 'Pop'
  let arr = []
  for (let i = 1; i <= n; i++) {
    arr.push(i)
  }

  let ret = []
  arr.forEach((item, index) => {
    if (!target.length) {
      return ret
    }
    if (target[0] === item) {
      ret.push(push)
      target.shift()
    } else {
      ret.push(push)
      ret.push(pop)
    }
  })
  return ret
}
