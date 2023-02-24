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
    
    void inorder(TreeNode* root,vector<int> &vec){
        
        //L - N - R 
        
        if(!root)return;
        
        inorder(root->left,vec);
        
        vec.push_back(root->val);
        
        inorder(root->right,vec);
        
        
    }
    
    int traversal(TreeNode* root,int i,int k){
        
        if(root==NULL)return 0;
        
        //L-N-R
        
        return traversal(root->left,i,k);
        
        i++;
        if(i==k)return root->val;
        
        return traversal(root->right,i,k);
        
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        //----INORDER TRAVERSAL-----
        
        vector<int> v;
        
        inorder(root,v);
        
        return v[k-1];
        
        
    }
};