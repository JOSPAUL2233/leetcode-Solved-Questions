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
    
    void solve(TreeNode* root,string &ans,string &path){
        
        if(root == NULL)
            return;
        
        path.push_back('a'+root->val);
        
        if(root->left == NULL && root->right==NULL){
            
            reverse(path.begin(),path.end());
            
            if(ans == "")
                ans = path;
            else
                ans = min (ans,path);
            
            reverse(path.begin(),path.end());
                        
        }
        
        
        
        solve(root->left,ans,path);
        solve(root->right,ans,path);
        
        path.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        string ans = "";
        string path = "";
        
        solve(root,ans,path);
        
        return ans;
        
    }
};