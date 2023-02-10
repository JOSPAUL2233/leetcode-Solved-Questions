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
    
    void solve(TreeNode* original,TreeNode* cloned,TreeNode* target,TreeNode* &ans){
        
        if(original==NULL || cloned==NULL)return;
        
        if(original==target){
            ans = cloned;
            return;
        }
        
        solve(original->left,cloned->left,target,ans);
        solve(original->right,cloned->right,target,ans);
        
    }
    
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* ans = new TreeNode(0);
        
        solve(original,cloned,target,ans);
        
        return ans;
        
        
    }
};