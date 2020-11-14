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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return r(nums,0,nums.size()-1);
    }

    TreeNode* r(vector<int>& nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = r(nums,left,mid-1);
        root->right = r(nums,mid+1,right);
        return root;
    }
};