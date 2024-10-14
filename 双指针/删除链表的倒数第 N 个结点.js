/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
  let front = (end = res = new ListNode());

  front.next = end.next = head;
  while (n--) {
    front = front.next;
  }

  while (front && front.next) {
    front = front.next;
    end = end.next;
  }

  end.next = end.next.next;
  return res.next;
};
