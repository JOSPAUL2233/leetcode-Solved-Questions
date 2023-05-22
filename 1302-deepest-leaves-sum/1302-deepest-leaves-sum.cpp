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
    
    void getHeight(TreeNode* root,int& height,int path){
        
        if(root->left == NULL && root->right == NULL){
            
            if(path>height)height = path;
            
        }
        
        if(root->left)getHeight(root->left,height,path+1);
        if(root->right)getHeight(root->right,height,path+1);
        
    }
    
    void getDeepestLeavesSum(TreeNode* root,int& ans,int height,int path){
        
        if(path==height){
            ans = ans + root->val;
            // cout<<"hello";
        }
        
        if(root->left)getDeepestLeavesSum(root->left,ans,height,path+1);
        if(root->right)getDeepestLeavesSum(root->right,ans,height,path+1);
        
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int height = 0;
        int path = 0;
        
        getHeight(root,height,path+1);
            
        int ans = 0;
        
        getDeepestLeavesSum(root,ans,height,path+1);
        
        return ans;
    }
};