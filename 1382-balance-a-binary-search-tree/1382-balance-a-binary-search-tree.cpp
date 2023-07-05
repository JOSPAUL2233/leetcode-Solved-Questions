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
    
    void getInorder(TreeNode* root,vector<TreeNode*> &inorder){
        
        if(root == NULL)
            return;
        
        getInorder(root->left,inorder);
        inorder.push_back(root);
        getInorder(root->right,inorder);
        
    }
    
    TreeNode* makeBST(vector<TreeNode*> inorder,int start,int end){
        
        //base case
        if(start > end)
            return NULL;
        
        int mid = start+(end - start)/2;
        
        //make a node for mid node
        TreeNode* root = inorder[mid];
        
        //take care of left and right part
        root->left = makeBST(inorder,start,mid-1);
        root->right = makeBST(inorder,mid+1,end);
        
        return root;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        //get the inorder
        vector<TreeNode*> inorder;
        getInorder(root,inorder);
        
        //construct tree from inorder
        TreeNode* newRoot = makeBST(inorder,0,inorder.size()-1);
        
        return newRoot;
        
    }
};