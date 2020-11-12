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
    int count=0;
public:
    void r(TreeNode* root,bool isLeft){
        if(!root)return;
        if(isLeft&&!root->left&&!root->right){
            count+=root->val;
        }
        r(root->left,true);
        r(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        r(root,false);
        return count;
    }
};