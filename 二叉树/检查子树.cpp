/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 问题分解，当找到与t2根节点相同的节点时，递归比较直到t1，t2==null，没找到递归检测t1左右子树
class Solution {
public:
    bool r(TreeNode* t1,TreeNode* t2){
        if(!t1&&!t2)return true;
        if(!t1||!t2)return false;
        return t1->val==t2->val&&r(t1->left,t2->left)&&r(t1->right,t2->right);
    }
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1)return t2==NULL;
        return r(t1,t2)||checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2);
    }
};