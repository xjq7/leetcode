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
    int ans;
public:
    void r(TreeNode* root,int sum){
        if(!root)return;
        sum=sum<<1|root->val;
        if((!root->left)&&(!root->right)){
            ans+=sum;
        }
        r(root->left,sum);
        r(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        r(root,0);
        return ans;
    }
};