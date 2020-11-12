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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                temp.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                q.pop();
            }
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};