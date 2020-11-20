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
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*> s;
        if(root->right)s.push(root->right);
        if(root->left)s.push(root->left);
        while(!s.empty()){
            TreeNode* cur=s.top();s.pop();
            if(cur->right)s.push(cur->right);
            if(cur->left)s.push(cur->left);
            root->right=cur;
            root->left=NULL;
            root=root->right;
        }
    }
};