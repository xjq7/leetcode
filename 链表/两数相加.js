/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let tmp = 0;

  let l3 = new ListNode();
  let res = l3;

  while (true) {
    if (!l1 && !l2) break;

    let l1value = 0,
      l2value = 0;
    if (l1) {
      l1value = l1.val;
      l1 = l1.next;
    }
    if (l2) {
      l2value = l2.val;
      l2 = l2.next;
    }

    let l3val = l1value + l2value + tmp;
    if (l3val > 9) {
      tmp = 1;
      l3val -= 10;
    } else {
      tmp = 0;
    }

    l3.next = new ListNode(l3val);
    l3 = l3.next;
  }

  if (tmp) {
    l3.next = new ListNode(tmp);
  }

  return res.next;
};
