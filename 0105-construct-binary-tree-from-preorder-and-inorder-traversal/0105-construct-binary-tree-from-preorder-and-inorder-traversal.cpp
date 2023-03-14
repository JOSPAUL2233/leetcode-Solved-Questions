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
    
    TreeNode* solve(vector<int> preorder,vector<int> inorder,int inStart,int inEnd,int &preStart,int preEnd,map<int,int> &m){
        
        if(preStart>preEnd || inStart > inEnd)return NULL;
        
        int element = preorder[preStart];
        
        TreeNode* root = new TreeNode(element);
        
        //USING MAP
        int index = m[element];
        
        
        preStart++;
        
        root->left = solve(preorder,inorder,inStart,index-1,preStart,preEnd,m);
        root->right = solve(preorder,inorder,index+1,inEnd,preStart,preEnd,m);
            
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start = 0;
        
        //using map to store the index of inorder so not to do a loop in every iteration to find its index
        
        map<int,int> m;
        for(int i = 0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        
        return solve(preorder,inorder,0,inorder.size()-1,start,preorder.size()-1,m);
        
    }
};