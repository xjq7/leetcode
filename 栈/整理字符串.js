/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function (s) {
  var regU = /[A-Z]/
  var regL = /[a-z]/

  function isU(str) {
    return regU.test(str)
  }
  function isL(str) {
    return regL.test(str)
  }
  var Stack = function () {
    this.arr = []
    this.top = null
    this.length = 0
  }
  Stack.prototype.push = function (x) {
    this.arr.push(x)
    this.length++
    this.top = x
  }
  Stack.prototype.pop = function () {
    this.arr.pop()
    this.length--
    this.top = this.arr[this.arr.length - 1]
  }

  var stack = new Stack()

  var sLen = s.length
  stack.push(s[0])
  for (index = 1; index < sLen; index++) {
    if ((isU(s[index]) && s[index].toLowerCase() === stack.top) || (isL(s[index]) && s[index].toUpperCase() === stack.top)) {
      stack.pop()
    } else {
      stack.push(s[index])
    }
  }
  return stack.arr.join('')
}
