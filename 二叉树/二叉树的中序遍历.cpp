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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        if(!root)return v;
        s.push(root);
        while(root&&!s.empty()){
            while(s.top()->left){
                s.push(s.top()->left);
            }
            while(!s.empty()){
                root=s.top();s.pop();
                v.push_back(root->val);
                if(root->right){
                    s.push(root->right);
                    break;
                };
            }
        }
        return v;
    }
};