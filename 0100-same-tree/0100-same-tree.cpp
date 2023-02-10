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
    
    void solve(TreeNode* p,TreeNode* q,bool &ans){
        
        if(p==NULL || q==NULL){
            
            if(p==NULL && q==NULL)return;
            else {
                ans = false;
                return;
            }   
            
        }
        
        if(!ans)return;
        
        if(p->val != q->val)ans=false;
        
        solve(p->left,q->left,ans);
        solve(p->right,q->right,ans);
        
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool ans = true;
        
        solve(p,q,ans);
        
        return ans;
    }
};