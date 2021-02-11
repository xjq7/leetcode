/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function (root, sum) {
  const res = []
  const path = []
  function recur(node, tar) {
    if (!node) return
    tar -= node.val
    path.push(node.val)
    if (tar === 0 && !node.left && !node.right) {
      res.push([...path])
    }
    recur(node.left, tar)
    recur(node.right, tar)
    path.pop()
  }
  recur(root, sum)
  return res
}
