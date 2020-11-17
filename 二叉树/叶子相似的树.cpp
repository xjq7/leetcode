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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s;
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        s.push(root1);
        while(!s.empty()){
            TreeNode* cur = s.top();s.pop();
            if(!cur->left&&!cur->right){
                v1.push_back(cur);
            }
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }
        s.push(root2);
        while(!s.empty()){
            TreeNode* cur = s.top();s.pop();
            if(!cur->left&&!cur->right){
                v2.push_back(cur);
            }
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }   
        if(v1.size()!=v2.size())return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]->val!=v2[i]->val)return false;
        }
        return true;

    }
};