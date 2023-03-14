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
    
    void solve(TreeNode* root,int temp,int &sum){
        
        if(root->left == NULL && root->right == NULL){
            temp = temp*10 + root->val;
            sum+=temp;
            return;
        }
        
        temp = temp*10 + root->val;
        
        if(root->left)
        solve(root->left,temp,sum);
        
        if(root->right)
        solve(root->right,temp,sum);
        
        temp = temp-root->val;
        temp/=10;
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        int temp = 0;
        
        solve(root,temp,sum);
        
        return sum;
        
    }
};