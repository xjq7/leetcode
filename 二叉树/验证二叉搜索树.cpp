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
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        long long  pre=(long long)INT_MAX+1;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            while(s.top()->left){
                s.push(s.top()->left);
            }
            while(!s.empty()){
                TreeNode* cur=s.top();s.pop();
                if(pre!=(long long)INT_MAX+1){
                    if(pre>=cur->val)return false; 
                }
                pre=cur->val;
                if(cur->right){
                    s.push(cur->right);
                    break;
                }
            }
        }
        return true;
    }
};