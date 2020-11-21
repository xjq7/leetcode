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
    void r(TreeNode* root,string &s){
        if(!root)return;
        s+=to_string(root->val);
        if(!root->left&&!root->right)return;
        s+="(";
        r(root->left,s);
        s+=")";
        if(root->right){
            s+="(";
            r(root->right,s);
            s+=")";
        }

    }
    string tree2str(TreeNode* t) {
        string s="";
        if(!t)return s;
        r(t,s);
        return s;
    }
};