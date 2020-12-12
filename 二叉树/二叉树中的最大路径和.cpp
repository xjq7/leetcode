/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum=-INT_MAX;
public:
    int r(TreeNode* root){
        if(root==nullptr)return 0;
        int leftSum = max(r(root->left),0);
        int rightSum = max(r(root->right),0);
        int curSum = root->val+leftSum+rightSum;
        maxSum=max(maxSum,curSum);
        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        r(root);
        return maxSum;
    }
};