/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeDuplicateNodes = function (head) {
  if (head === null) {
    return head
  }
  const map = {}

  map[head.val] = true
  let node = head.next
  let prev = head
  while (node) {
    if (map[node.val] !== undefined) {
      prev.next = node.next
    } else {
      map[node.val] = true
      prev = prev.next
    }
    node = node.next
  }
  return head
}
