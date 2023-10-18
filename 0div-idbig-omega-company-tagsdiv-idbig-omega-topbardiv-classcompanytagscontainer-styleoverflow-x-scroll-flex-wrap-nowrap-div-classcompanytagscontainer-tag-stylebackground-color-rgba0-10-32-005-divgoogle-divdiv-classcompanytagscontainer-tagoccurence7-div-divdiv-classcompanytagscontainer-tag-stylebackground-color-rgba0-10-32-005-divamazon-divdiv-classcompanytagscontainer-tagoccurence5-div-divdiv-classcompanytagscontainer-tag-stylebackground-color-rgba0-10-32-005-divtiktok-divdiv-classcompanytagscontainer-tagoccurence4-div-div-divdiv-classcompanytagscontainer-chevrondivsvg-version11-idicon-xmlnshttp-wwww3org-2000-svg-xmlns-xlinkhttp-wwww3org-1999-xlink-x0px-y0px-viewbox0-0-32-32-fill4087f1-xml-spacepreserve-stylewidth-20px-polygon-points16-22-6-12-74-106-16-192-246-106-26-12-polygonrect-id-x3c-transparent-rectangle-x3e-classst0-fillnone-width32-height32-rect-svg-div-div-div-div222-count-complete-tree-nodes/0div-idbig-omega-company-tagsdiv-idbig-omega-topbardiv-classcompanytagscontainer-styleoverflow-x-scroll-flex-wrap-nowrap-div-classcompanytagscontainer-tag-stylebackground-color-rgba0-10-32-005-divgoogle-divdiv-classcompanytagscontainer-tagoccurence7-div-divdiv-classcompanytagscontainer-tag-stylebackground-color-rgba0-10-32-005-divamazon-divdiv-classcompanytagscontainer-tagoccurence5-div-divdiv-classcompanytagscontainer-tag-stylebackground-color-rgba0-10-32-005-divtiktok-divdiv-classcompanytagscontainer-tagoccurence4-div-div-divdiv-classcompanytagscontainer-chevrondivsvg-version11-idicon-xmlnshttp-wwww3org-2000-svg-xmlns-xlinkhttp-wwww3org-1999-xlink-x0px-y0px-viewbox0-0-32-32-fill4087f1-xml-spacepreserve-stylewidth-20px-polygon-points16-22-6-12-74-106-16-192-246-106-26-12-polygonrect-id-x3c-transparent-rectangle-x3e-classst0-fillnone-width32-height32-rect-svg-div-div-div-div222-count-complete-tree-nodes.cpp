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
    
    int getLeftHeight(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        return 1 + getLeftHeight(root->left);
        
    }
    
    int getRightHeight(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        return 1 + getRightHeight(root->right);
        
    }
    
    int countNodes(TreeNode* root) {
        
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);
        
        if(leftHeight == rightHeight){
            
            //calculate the number of nodes using
            //height of balanced binary tree
            return pow(2,leftHeight) - 1;
            
        }else{
            
            return 1 + countNodes(root->left) + countNodes(root->right);
            
        }
        
    }
};