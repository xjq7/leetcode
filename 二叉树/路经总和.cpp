/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if((!root->left)&&(!root->right)&&root->val==sum)return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};

// 迭代
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        stack<pair<TreeNode*,int>> s;
        s.push(pair<TreeNode*,int>(root,root->val));
        while(!s.empty()){
            auto curPair = s.top();s.pop(); 
            TreeNode* cur = curPair.first;
            int curCount = curPair.second;
            if(cur->right){
                s.push(pair<TreeNode*,int>(cur->right,curCount+cur->right->val));
            }
            if(cur->left){
                s.push(pair<TreeNode*,int>(cur->left,curCount+cur->left->val));
            }
            if(!cur->left&&!cur->right){
                if(curCount==sum)return true;
            }
        }        
        return false;
    }
};