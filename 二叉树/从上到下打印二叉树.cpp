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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root); 
        while(!q.empty()){
            TreeNode* cur=q.front();q.pop();
            v.push_back(cur->val);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
        return v;
    }
};