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
    
    void inorder(TreeNode* root,vector<int> &ans,int &freq,int &maxFreq,int &val){
        
        //base case
        if(root == NULL)
            return;
        
        inorder(root->left,ans,freq,maxFreq,val);
        
        //do the operation here--------
        
        //update the freq , and value if needed
        if(val == root->val)
            freq++;
        else{
            
            val = root->val;
            freq = 1;
            
        }
        
        //update the maxFreq, and ans if needed
        if(freq > maxFreq){
            
            maxFreq = freq;
            ans = {val};
            
        }else if(freq == maxFreq){
            
            ans.push_back(val);
            
        }
            
        inorder(root->right,ans,freq,maxFreq,val);
        
        
    }
    
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        
        //maintian three tracks
        int freq = 0;
        int maxFreq = 0;
        int val = INT_MIN;
        
        inorder(root,ans,freq,maxFreq,val);
        
        return ans;
        
    }
};