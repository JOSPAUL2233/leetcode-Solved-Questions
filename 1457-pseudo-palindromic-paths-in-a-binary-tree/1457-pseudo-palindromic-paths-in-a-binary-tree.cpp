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
    
    bool check(map<int,int> freq){
                
        int count = 0;
        
        for(auto i : freq)
            if(i.second % 2 != 0)
                count++;
        
        return count<=1;
        
    }
    
    void solve(TreeNode* root,int &count,map<int,int> &freq){
        
        //base case
        if(!root->left && !root->right){
            
            freq[root->val]++;
            
            if(check(freq))
                count++;
            
            freq[root->val]--;
                        
            return;
            
        }
        
        freq[root->val]++;
        
        if(root->left)
            solve(root->left,count,freq);
        
        if(root->right)
            solve(root->right,count,freq);
        
        freq[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int count = 0;
        map<int,int> freq;
        
        solve(root,count,freq);
        
        return count;
        
    }
};