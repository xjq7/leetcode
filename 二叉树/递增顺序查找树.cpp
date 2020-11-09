/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归解法
class Solution {
    TreeNode* head=new TreeNode();TreeNode* cur=head;
public:
    void inOrder(TreeNode* root){
        if(!root)return;
        inOrder(root->left);
        cur->right=new TreeNode(root->val);
        cur=cur->right;
        inOrder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        return head->right;
    }
};