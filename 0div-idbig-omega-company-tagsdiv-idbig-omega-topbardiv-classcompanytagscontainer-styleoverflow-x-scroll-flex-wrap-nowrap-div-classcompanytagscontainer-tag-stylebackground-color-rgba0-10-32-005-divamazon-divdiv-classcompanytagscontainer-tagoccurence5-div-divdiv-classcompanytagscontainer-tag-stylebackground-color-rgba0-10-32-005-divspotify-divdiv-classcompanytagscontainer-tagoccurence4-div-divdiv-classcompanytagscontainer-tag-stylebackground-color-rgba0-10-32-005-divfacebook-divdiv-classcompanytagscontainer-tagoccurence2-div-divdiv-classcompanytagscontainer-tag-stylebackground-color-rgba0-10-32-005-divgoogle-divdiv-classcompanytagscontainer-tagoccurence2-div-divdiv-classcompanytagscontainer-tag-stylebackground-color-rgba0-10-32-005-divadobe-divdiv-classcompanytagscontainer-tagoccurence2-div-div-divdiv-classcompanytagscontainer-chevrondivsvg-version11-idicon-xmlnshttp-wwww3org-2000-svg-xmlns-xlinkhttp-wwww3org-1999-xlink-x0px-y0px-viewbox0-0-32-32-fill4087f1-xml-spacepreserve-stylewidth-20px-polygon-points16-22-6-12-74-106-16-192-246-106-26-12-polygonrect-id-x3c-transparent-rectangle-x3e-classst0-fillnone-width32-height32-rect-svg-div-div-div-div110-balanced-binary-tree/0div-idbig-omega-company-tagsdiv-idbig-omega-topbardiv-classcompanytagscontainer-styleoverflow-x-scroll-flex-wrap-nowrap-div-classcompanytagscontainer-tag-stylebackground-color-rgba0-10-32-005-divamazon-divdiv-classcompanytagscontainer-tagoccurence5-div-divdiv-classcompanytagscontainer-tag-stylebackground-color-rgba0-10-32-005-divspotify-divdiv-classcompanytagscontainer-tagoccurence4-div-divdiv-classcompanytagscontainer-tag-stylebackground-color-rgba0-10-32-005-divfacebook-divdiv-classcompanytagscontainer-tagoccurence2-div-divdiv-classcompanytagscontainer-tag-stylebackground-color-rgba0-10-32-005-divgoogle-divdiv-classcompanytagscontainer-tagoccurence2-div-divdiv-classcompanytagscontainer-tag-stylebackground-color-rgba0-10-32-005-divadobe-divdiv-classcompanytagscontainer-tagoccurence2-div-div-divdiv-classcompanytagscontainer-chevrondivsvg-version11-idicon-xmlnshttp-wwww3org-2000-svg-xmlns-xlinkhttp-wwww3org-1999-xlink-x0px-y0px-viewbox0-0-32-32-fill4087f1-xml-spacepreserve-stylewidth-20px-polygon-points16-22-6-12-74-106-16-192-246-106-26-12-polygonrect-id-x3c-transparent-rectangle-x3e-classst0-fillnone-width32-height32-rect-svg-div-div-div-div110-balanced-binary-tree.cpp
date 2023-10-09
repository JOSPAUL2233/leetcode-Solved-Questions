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
    
    pair<int,bool> solve(TreeNode* root){
        
        if(root == NULL){
            return {0,true};
        }
        
        //get pairs from left and right
        pair<int,bool> left = solve(root->left);
        
        if(left.second == false)
            return {-1,false};
        
        pair<int,bool> right = solve(root->right);
        
        if(right.second == false)
            return {-1,false};

        int leftHeight = left.first;
        int rightHeight = right.first;
        
        int diff = abs(leftHeight-rightHeight);
        
        bool isBalanced = diff <= 1 ? true : false;
        
        return {1 + max(leftHeight,rightHeight),isBalanced};
        
    }
    
    bool isBalanced(TreeNode* root) {
                
        return solve(root).second;
        
    }
    
};