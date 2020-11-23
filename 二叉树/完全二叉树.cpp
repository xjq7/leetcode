/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二分查找
class Solution {
public:

    bool isExist(TreeNode* root,int level,int k){
        int bits=1<<(level-1);
        TreeNode* node=root;
        while(node && bits>0){
            if((bits & k)==0){
                node=node->left;
            }else{
                node=node->right;
            }
            bits >>=1;
        }
        return node!=NULL;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        TreeNode* node=root;
        int level=0;
        while(node->left){
            level++;
            node=node->left;
        }
        int low=1<<level,hi=(1<<(level+1))-1;
        while(low<hi){
            int mid = (hi-low+1)/2+low;
            if(isExist(root,level,mid)){
                low=mid;
            }else{
                hi=mid-1;
            }
        }
        return low;
    }
};