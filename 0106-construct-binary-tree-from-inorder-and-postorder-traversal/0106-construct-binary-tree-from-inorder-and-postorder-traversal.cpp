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
    
    TreeNode* solve(vector<int> inorder,vector<int> postorder, int inStart,int inEnd,int postStart,int &i,map<int,int> &m){
        
        // i should be passed by reference since i keeps changing
        // m should be passed by referecne since it takes O(n) time to copy m each time - so pass the reference instead
        
        
        
        if(i<0 || inStart > inEnd) return NULL;
        
        int element = postorder[i];
        
        TreeNode* root = new TreeNode(element);
        
        int index = m[element];
        
        i--;
        
        root->right = solve(inorder,postorder,index+1,inEnd,postStart,i,m);
        root->left = solve(inorder,postorder,inStart,index-1,postStart,i,m);
     
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        //MAP
        map<int,int> m;
        
        for(int i = 0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        
        int i = postorder.size()-1;
        
        return solve(inorder,postorder,0,inorder.size()-1,0,i,m);
        
        
    }
};