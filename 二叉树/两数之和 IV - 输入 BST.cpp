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
    void r(TreeNode* root,vector<int> &v){
        if(!root)return;
        r(root->left,v);
        v.push_back(root->val);
        r(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        r(root,v);
        int i=0,j=v.size()-1;
        while(i<j){
            if((v[i]+v[j])==k){
                return true;
            }else if((v[i]+v[j])>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};