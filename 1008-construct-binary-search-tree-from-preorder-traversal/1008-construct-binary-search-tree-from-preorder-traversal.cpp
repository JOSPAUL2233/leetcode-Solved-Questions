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
    
    TreeNode* makeBST(vector<int> preorder, int &index, int min, int max){
        
        if(index == preorder.size())
            return NULL;
        
        int val = preorder[index];
        
        //go for further tree if the condition satisfies
        if(val > min && val < max){
            
            //make current node
            TreeNode* root = new TreeNode(val);
            
            index++;
            //take care of left and right part
            root->left = makeBST(preorder,index,min,val);
            root->right = makeBST(preorder,index,val,max);
            
            return root;
            
        }else{//return NULL if the condition fails
            return NULL;
        }
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        //fix a range
        int min = INT_MIN;
        int max = INT_MAX;
        
        int index = 0;
        
        TreeNode* root = makeBST(preorder,index,min,max);
        
        return root;
        
    }
};