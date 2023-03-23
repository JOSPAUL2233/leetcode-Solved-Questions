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
    
    void solve(TreeNode* root,int &min,int depth){
        
        
        //BASE CASE
        if(root->left==NULL && root->right==NULL){
            
            if(depth<min)min = depth;
            
            return;
            
        }
        
        
        if(root->left)
            solve(root->left,min,depth+1);
        
        if(root->right)
            solve(root->right,min,depth+1);
        
    }
    
public:
    int minDepth(TreeNode* root) {
        
        if(!root)return 0;
        
        int min = INT_MAX;
        
        int depth = 1;
        
        solve(root,min,depth);
        
        return min;
        
    }
};