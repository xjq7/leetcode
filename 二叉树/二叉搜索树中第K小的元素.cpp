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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return 0;
        stack<TreeNode*> s;
        s.push(root);
        vector<int> v;
        while(!s.empty()){
            while(s.top()->left){
                if(s.top()->left)s.push(s.top()->left);
            }
            while(!s.empty()){
                TreeNode* cur=s.top();s.pop();
                v.push_back(cur->val);
                if(cur->right){
                    s.push(cur->right);
                    break;
                }
            }
        }
        return v[--k];
    }
};