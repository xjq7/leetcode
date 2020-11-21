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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            l++;
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();q.pop();
                temp.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);  
            }
            if(l%2==0)reverse(temp.begin(),temp.end());
            v.push_back(temp);
        }
        return v;
    }
};

// 双端队列
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        deque<TreeNode*> q;
        q.push_front(root);
        bool f=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                if(!f){
                    TreeNode* cur = q.back();q.pop_back();
                    temp.push_back(cur->val);
                    if(cur->right)q.push_front(cur->right);  
                    if(cur->left)q.push_front(cur->left);
                }else{
                    TreeNode* cur = q.front();q.pop_front();
                    temp.push_back(cur->val);
                    if(cur->left)q.push_back(cur->left);
                    if(cur->right)q.push_back(cur->right);  
                }
            }
            f=!f;
            v.push_back(temp);
        }
        return v;
    }
};