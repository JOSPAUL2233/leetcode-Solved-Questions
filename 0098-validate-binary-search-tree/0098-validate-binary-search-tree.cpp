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
    
    bool isBST(TreeNode* root,long min,long max){
        
        if(root==NULL)return true;
        
        if(root->val > min && root->val < max){
            
            bool leftPart = isBST(root->left,min,root->val);
            bool rightPart = isBST(root->right,root->val,max);
            
            return leftPart && rightPart;
            
        }else{
            return false;
        }
        
    }
    
    void solve(TreeNode* root,vector<int> &v){
        
        if(root==NULL)return;
        //left
        solve(root->left,v);
        
        //operation
        v.push_back(root->val);
        
        //right
        solve(root->right,v);
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        //INORDER TRAVERSAL - L N R
        
//         vector<int> v;
//         solve(root,v);
        
//         for(int i = 0;i<v.size()-1;i++){
        
//             if(v[i]>=v[i+1])return false;
        
//         }
        
        // WITHOUT EXTRA SPACE(NOT INORDER)
        
        long min = LONG_MIN;
        long max = LONG_MAX;
        
        return isBST(root,min,max);
        
    }
};