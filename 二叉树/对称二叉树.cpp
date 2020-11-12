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
    bool r(TreeNode* left,TreeNode* right){
        if((!left&&right)||(left&&!right)){
            return false;
        }else if(!left&&!right){
            return true;
        }else if(left->val!=right->val){
            return false;
        }else{
            return r(left->right,right->left)&&r(left->left,right->right);
        };
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return r(root->left,root->right);
    }
};