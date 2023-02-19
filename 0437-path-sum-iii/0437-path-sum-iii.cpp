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
    
    void solve(TreeNode* root,int k,vector<long> &ans,int &count){
        
        if(root==NULL)return;
        
        ans.push_back(root->val);
        long sum = 0;
        for(int i = ans.size()-1;i>=0;i--){
            
            sum+=ans[i];
            if(sum==k){
                count++;
            }
            
        }
        
        solve(root->left,k,ans,count);
        solve(root->right,k,ans,count);
        
        ans.pop_back();
        
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        vector<long> ans;
        int count = 0;
        
        solve(root,targetSum,ans,count);
        
        return count;
        
    }
};