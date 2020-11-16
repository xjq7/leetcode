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
    int min=INT_MAX;int pre=INT_MAX;
public:
    void r(TreeNode* root){
        if(!root)return;
        r(root->left);
        int diff=abs(pre-root->val);
        if(diff<min){
            min=diff;
        }
        pre=root->val;
        r(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        r(root);
        return min;
    }
};