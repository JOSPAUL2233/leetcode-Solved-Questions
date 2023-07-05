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
    
    void preorder(TreeNode* root, vector<TreeNode*> &nodes){
        
        if(root == NULL)
            return;
        
        nodes.push_back(root);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        
    }
    
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> nodes;
        
        //store preorder
        preorder(root,nodes);
        
        //flatten it
        for(int i = 0;i<nodes.size();i++){
            
            nodes[i]->left = NULL;
            
            //for last node
            if(i == nodes.size()-1)
                nodes[i]->right = NULL;
            else
                nodes[i]->right = nodes[i+1];
        }
        
    }
};