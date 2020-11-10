/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root?recur(root->left,root->right):true;
    }
    bool recur(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL)return true;
        if((left==NULL&&right!=NULL)||(left!=NULL&&right==NULL))return false;
        if(left->val!=right->val)return false;
        return recur(left->left,right->right)&&recur(left->right,right->left);
    }
};