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
    
    // RIGHT - LEFT - NODE
    void inversePreorder(TreeNode* root, TreeNode* &prev){
        
        //base case
        if(root == NULL)
            return;
        
        inversePreorder(root->right,prev);
        inversePreorder(root->left,prev);
        
        root->right = prev;
        root->left = NULL;
        
        //keep track of current Node as the last node for next node
        prev = root;
        
    }
    
    void flatten(TreeNode* root) {
        
        TreeNode* prev = NULL;//keep a track of prev Node, which is also acts as tail
        
        inversePreorder(root,prev);
                
    }
};