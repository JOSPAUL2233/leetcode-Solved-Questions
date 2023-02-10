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
    
    void solve(TreeNode* root,int height,int &maxHeight){
        
        
        if(root==NULL){
            maxHeight = max(maxHeight,height);
            return;
        }
        
        height++;
        solve(root->left,height,maxHeight);
        height--;
        
        height++;
        solve(root->right,height,maxHeight);
        height--;
        
    }
    
public:
    int maxDepth(TreeNode* root) {
        
        int maxHeight = 0;
        
        solve(root,0,maxHeight);
        
        return maxHeight;
        
    }
};