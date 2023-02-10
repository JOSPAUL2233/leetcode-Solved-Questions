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
    
    void solve(TreeNode* Rleft,TreeNode* Rright,bool &ans){
        
        if(Rleft == NULL && Rright==NULL)return;
        
        if(Rleft==NULL || Rright==NULL){
            ans = false;
            return;
        }
        
        if(!ans)return;
        
        if(Rleft->val != Rright->val){
            ans = false;
            return;
        }
        
        solve(Rleft->left,Rright->right,ans);
        
        solve(Rleft->right,Rright->left,ans);
        
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        
        bool ans = true;
        
        solve(root->left,root->right,ans);
        
        return ans;
        
    }
};