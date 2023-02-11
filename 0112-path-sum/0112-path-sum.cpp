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
    
    void solve(TreeNode* root,int targetSum,int sum,bool &ans){
        
        if(root==NULL)return;
        
        if(root->left==NULL && root->right==NULL){
            
            sum+=root->val;
            
            if(sum==targetSum)ans = true;
            return;
            
        }
        
        if(ans)return;
        
        sum+=root->val;
        solve(root->left,targetSum,sum,ans);
        
        solve(root->right,targetSum,sum,ans);
        sum-=root->val;
        
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool ans = false;
        
        if(root==NULL)return ans;
        
        solve(root,targetSum,0,ans);
        
        return ans;
        
    }
};