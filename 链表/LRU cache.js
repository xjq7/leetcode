function Node({ val, key, next = null, prev = null }) {
  this.val = val
  this.key = key
  this.next = next
  this.prev = prev
}

function LinkList() {
  this.head = new Node({ val: null, key: null })
  this.length = 0
}

LinkList.prototype.insertAsEnd = function (node) {
  const position = this.length ? this.head.prev : this.head
  this.insertAsNode(position, node)
}

LinkList.prototype.insertAsNode = function (node, newNode) {
  const nodeNext = node.next
  if (nodeNext) {
    newNode.next = nodeNext
    nodeNext.prev = newNode
    node.next = newNode
    newNode.prev = node
  } else {
    newNode.next = this.head
    newNode.prev = this.head
    this.head.next = newNode
    this.head.prev = newNode
  }
  this.length++
}

LinkList.prototype.insertAsHead = function (node) {
  this.insertAsNode(this.head, node)
}

LinkList.prototype.remove = function (node) {
  const nodePrev = node.prev
  const nodeNext = node.next
  if (nodePrev === nodeNext) {
    this.head.prev = this.head.next = null
  } else {
    nodePrev.next = nodeNext
    nodeNext.prev = nodePrev
  }
  this.length--
}

LinkList.prototype.toString = function () {
  let head = this.head.next
  let len = this.length
  while (len) {
    console.log(head)
    head = head.next
    len--
  }
}

var LRUCache = function (capacity) {
  this.capacity = capacity
  this.size = 0
  this.l = new LinkList()
  this.cache = {}
}

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
  const keyNode = this.cache[key]
  if (keyNode === undefined) return -1
  this.updateKey(key)
  return keyNode.val
}

LRUCache.prototype.updateKey = function (key) {
  const keyNode = this.cache[key]
  this.l.remove(keyNode)
  this.l.insertAsEnd(keyNode)
}

LRUCache.prototype.remove = function (key) {
  const keyNode = this.cache[key]
  this.l.remove(keyNode)
  delete this.cache[key]
  this.size--
}

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
  const keyNode = this.cache[key]
  if (keyNode === undefined) {
    if (this.size >= this.capacity) {
      const rmKey = this.l.head.next.key
      this.remove(rmKey)
    }
    this.cache[key] = new Node({ key, val: value })
    this.l.insertAsEnd(this.cache[key])
    this.size++
  } else {
    this.cache[key].val = value
    this.updateKey(key)
  }
}
