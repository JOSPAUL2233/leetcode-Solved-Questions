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
    
    int getMin(TreeNode* root){
        
        //base case
        if(!root->left){
            
            return root->val;
            
        }
        
        return getMin(root->left);
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return NULL;
        
        if(root->val == key){
            
            //0 child
            if(!root->left && !root->right){
                
                delete root;
                return NULL;
                
            }
            
            //1 child
            
            //left child
            if(root->left &&  !root->right){
                
                TreeNode* temp = root->left;
                delete root;
                return temp;
                
            }
            
            //right child
            if(root->right && !root->left){
                
                TreeNode* temp = root->right;
                delete root;
                return temp;
                
            }
                
            //2 child
            if(root->left && root->right){
                
                int mini = getMin(root->right);
                root->val = mini;
                
                root->right = deleteNode(root->right,mini);
                
                return root;
                
            }
            
        }
        
        //redirect if the key is not yet found
        
        if(root->val > key)
            root->left =  deleteNode(root->left,key);
        else
            root->right =  deleteNode(root->right,key);
        
        return root;
        
    }
};