/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
  var stack = []
  while (head) {
    stack.push(head.val)
    head = head.next
  }
  var l = 0,
    r = stack.length - 1
  while (l < r) {
    if (stack[l] !== stack[r]) {
      return false
    }
    l++
    r--
  }
  return true
}
