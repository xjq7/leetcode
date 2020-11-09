/**
 * initialize your data structure here.
 */
var MinStack = function () {
  this.arr = []
  this.length = 0
  var HelpMinStack = function () {
    this.arr = []
  }

  HelpMinStack.prototype.push = function (x) {
    this.arr.push(x)
  }

  HelpMinStack.prototype.pop = function () {
    this.arr.pop()
  }

  HelpMinStack.prototype.top = function () {
    return this.arr[this.arr.length - 1]
  }
  var h = new HelpMinStack()
  this.h = h
}

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
  this.arr.push(x)
  this.length++

  const t = this.h.top()
  if (t === undefined) {
    this.h.push(x)
  } else {
    if (x < t) {
      this.h.push(x)
    } else {
      this.h.push(t)
    }
  }
}

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
  this.length--
  this.arr.pop()
  this.h.pop()
}

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
  return this.arr[this.length - 1]
}

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
  return this.h.top()
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
