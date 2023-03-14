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
    
    TreeNode* solve(vector<int> preorder,vector<int> inorder,int inStart,int inEnd,int &preStart,int preEnd){
        
        if(preStart>preEnd || inStart > inEnd)return NULL;
        
        int element = preorder[preStart];
        
        TreeNode* root = new TreeNode(element);
        
        int index = 0;
        
        // find the index position
        
        for(int i = inStart;i<=inEnd;i++){
            if(inorder[i]==element){
                index = i;
                break;
            }
        }
        
        preStart++;
        
        root->left = solve(preorder,inorder,inStart,index-1,preStart,preEnd);
        root->right = solve(preorder,inorder,index+1,inEnd,preStart,preEnd);
            
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start = 0;
        
        return solve(preorder,inorder,0,inorder.size()-1,start,preorder.size()-1);
        
    }
};