function A(root) {
  let stack = []
  stack.push(root)
  while (stack.length) {
    let cur = stack[stack.length - 1]
    stack.pop()
    console.log(cur.val)
    if (cur.right) stack.push(cur.right)
    if (cur.left) stack.push(cur.left)
  }
}
