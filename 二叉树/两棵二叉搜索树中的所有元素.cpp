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
    void r(TreeNode* root,vector<int> &v){
        if(!root)return;

        r(root->left,v);
        v.push_back(root->val);
        r(root->right,v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,v3;
        r(root1,v1);
        r(root2,v2);
        int i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            if(v1[i]<v2[j]){
                v3.push_back(v1[i++]);
            }else{
                v3.push_back(v2[j++]);
            }
        }

        while(i<v1.size()){
            v3.push_back(v1[i++]);
        }
        while(j<v2.size()){
            v3.push_back(v2[j++]);
        }
        return v3;

    }
};