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
    
    void preorder(TreeNode* root, string &ans){
        
        
        ans.append(to_string(root->val));

        if(root->left){
            ans.push_back('(');
            preorder(root->left,ans);
            ans.push_back(')');
        }
        
        if(!root->left && root->right){
            ans.append("()");
        }
                
        if(root->right){
            ans.push_back('(');
            preorder(root->right,ans);
            ans.push_back(')');        
        }

    }
    
    string tree2str(TreeNode* root) {
        
        string ans = "";
        
        preorder(root,ans);
        
        return ans;
        
    }
};