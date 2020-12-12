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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        TreeNode* n=root;
        while(n!=nullptr){
            if(val<n->val){
                if(n->left==nullptr){
                    n->left=new TreeNode(val);
                    break;
                }else{
                    n=n->left;
                }
            }else{
                if(n->right==nullptr){
                    n->right=new TreeNode(val);
                    break;
                }else{
                    n=n->right;
                }
            }
        }
        return root;
    }
};