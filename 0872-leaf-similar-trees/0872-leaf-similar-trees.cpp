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
    
    void storeleaf(TreeNode* root,vector<int> &vec){
        
        if(root==NULL)return;
        
        if(root->left==NULL && root->right==NULL){
            
            vec.push_back(root->val);
            return;
            
        }
        
        storeleaf(root->left,vec);
        storeleaf(root->right,vec);
        
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> vec1;
        vector<int> vec2;
        
        storeleaf(root1,vec1);
        storeleaf(root2,vec2);
        
        if(vec1.size() != vec2.size())return false;
        
        for(int i = 0;i<vec1.size();i++){
            if(vec1[i]!=vec2[i])return false;
        }
        
        return true;
        
    }
};