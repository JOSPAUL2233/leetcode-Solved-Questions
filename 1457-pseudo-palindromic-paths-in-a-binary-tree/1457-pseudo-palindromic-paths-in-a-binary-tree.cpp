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
    
    bool check(int odds){
        
        return (odds == 0) ||(( odds & (odds-1)) == 0);
        
    }
    
    void solve(TreeNode* root,int &count,int &odds){
        
        //base case
        
        int mask = 1<<root->val;
        odds ^= mask;
        
        if(!root->left && !root->right){
            
           if(check(odds))
               count++;
            
        }
        
        if(root->left)
            solve(root->left,count,odds);
        
        if(root->right)
            solve(root->right,count,odds);
        
        odds ^= mask;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int count = 0;
        int odds = 0;
        
        solve(root,count,odds);
        
        return count;
        
    }
};