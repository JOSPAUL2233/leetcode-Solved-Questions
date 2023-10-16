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

    
    bool solve(TreeNode* leftRoot,TreeNode* rightRoot){
        
        //check for leaf node
        if(leftRoot == NULL && rightRoot == NULL)
            return true;
        
        //check for mirror behaviour
        if(leftRoot == NULL || rightRoot == NULL)
            return false;
        
        // cout<<leftRoot->val<<endl<<rightRoot->val<<endl;
        
        if(leftRoot->val != rightRoot->val)
            return false;
        
        
        //check for other nodes
        if(!solve(leftRoot->left,rightRoot->right))
            return false;
        
        if(!solve(leftRoot->right,rightRoot->left))
            return false;
        
        return true;
        
    }
    bool isSymmetric(TreeNode* root) {
        
        //if only root node
        if(root->left == NULL && root->right == NULL)
            return true;
        
        if(root->left == NULL || root->right == NULL)
            return false;
        
        bool ans = solve(root->left,root->right);
        
        return ans;
        
    }
};