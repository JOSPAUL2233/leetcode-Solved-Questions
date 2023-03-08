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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size()==0)return NULL;
        
        vector<int> left;
        vector<int> right;
        
        int maxIndex = 0;
        
        //finding the maximum
        
        for(int i = 1;i<nums.size();i++){
            
            if(nums[i]>nums[maxIndex])maxIndex = i;
            
        }
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        
        //seperating left and right
        
        for(int i = 0;i<maxIndex;i++){
            
            left.push_back(nums[i]);
            
        }
        
        for(int i = maxIndex+1;i<nums.size();i++){
            
            right.push_back(nums[i]);
            
        }
        
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        
        return root;
        
    }
};