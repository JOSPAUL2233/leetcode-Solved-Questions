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
    
    bool areIdentical(TreeNode* root1,TreeNode* root2){
        
        //base case--
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
            
        //if the data is different, they are not identical
        if(root1->val != root2->val)
            return false;
            
        //check for left and right sides
        if(!areIdentical(root1->left,root2->left))
            return false;
            
        if(!areIdentical(root1->right,root2->right))
            return false;
        
        return true;
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //base case--
        
        //if the root reaches at the end and didn't find any answer
        if(root == NULL)
            return false;
        
        //if the subRoot is NULL, then subRoot is always subTree of root
        if(subRoot == NULL)
            return true;
            
        //check for whenter root and subRoot are identical or not
        if(areIdentical(root,subRoot))
            return true;

        //check for left and right part of root
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        
        //return if any of the left or right part are identical
        return left || right;        
    }
};