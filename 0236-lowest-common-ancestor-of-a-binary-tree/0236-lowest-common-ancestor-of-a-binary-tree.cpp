/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        //if it reaches any of the node
        if(root == p || root == q)
            return root;
        
        //go and get the left and right side nodes if it is found
        TreeNode* leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSide = lowestCommonAncestor(root->right, p, q);
        
        //conditions for returning
        if(leftSide && rightSide)
            return root;
        else if(leftSide && !rightSide)
            return leftSide;
        else if(rightSide && !leftSide)
            return rightSide;
        else//when leftSide and rightSide both are NULL
            return NULL;
        
    }
};