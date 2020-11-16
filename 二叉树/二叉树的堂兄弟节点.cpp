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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        pair<TreeNode*,int> a;
        pair<TreeNode*,int> b;
        int d;
        while(!q.empty()){
            d++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                if(cur->left){
                    if(cur->left->val==x){
                        a=pair<TreeNode*,int>(cur,d);
                    }
                    if(cur->left->val==y){
                        b=pair<TreeNode*,int>(cur,d);
                    }
                    q.push(cur->left);
                }
                if(cur->right){
                    if(cur->right->val==x){
                        a=pair<TreeNode*,int>(cur,d);
                    }
                    if(cur->right->val==y){
                        b=pair<TreeNode*,int>(cur,d);
                    }
                    q.push(cur->right);
                }
            }
        }
        return (a.first!=b.first)&&(a.second==b.second);
    }
};