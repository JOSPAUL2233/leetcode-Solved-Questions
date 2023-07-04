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
    TreeNode* searchBST(TreeNode* root, int val) {
//-----------RECURSIVE WAY -----------------------
        
        if(root==NULL)return NULL;
       
        if(root->val == val)return root;
        
        //go to right if : val > current val of root
        if(val > root->val){
            
            return searchBST(root->right,val);
            
        }else{
            
            return searchBST(root->left,val);
            
        }
        
//------------ITERATIVE WAY---------------------
        
//         TreeNode* temp = root;
        
//         while(temp != NULL){
                        
//             if(temp->val==val)return temp;
            
//             if(temp->val>val)temp = temp->left;
//             else temp = temp->right;
            
//         }
         
//     return NULL;//if the element is not found
    }
};