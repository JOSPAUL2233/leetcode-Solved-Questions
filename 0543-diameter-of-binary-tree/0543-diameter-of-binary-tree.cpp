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
    
    int getHeight(TreeNode* root,int &diameter){
        
        //base case
        if(root == NULL)
            return 0;
        
        int leftHeight = getHeight(root->left,diameter);
        int rightHeight = getHeight(root->right,diameter);
        
        int currDia = leftHeight + rightHeight;
        
        int currHeight = max(leftHeight,rightHeight) + 1;
        
        diameter = max(diameter,currDia);
        
        return currHeight;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        getHeight(root,diameter);
        
        return diameter;
        
    }
};