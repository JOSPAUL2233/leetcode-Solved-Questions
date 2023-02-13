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
    
    pair<bool,int> solve(TreeNode* root){
        
        //base case
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        
        bool balanced = false;
        
        int height = max(left.second,right.second)+1;
        
        int diff = abs(left.second - right.second);
        
        if(left.first && right.first && (diff<=1))
            balanced = true;
        
        pair<bool,int> p = make_pair(balanced,height);
        return p;
   
        
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};