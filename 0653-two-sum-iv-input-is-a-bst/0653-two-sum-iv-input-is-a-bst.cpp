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
    
    void inorder(TreeNode* root,vector<int> &nodes){
        
        if(root == NULL)
            return;
        
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        //get the inorder
        vector<int> nodes;
        inorder(root,nodes);
        
        //using two pointers approach, do twoSum in sorted array
        int left = 0;
        int right = nodes.size()-1;
        
        while(left < right){
            
            int sum = nodes[left] + nodes[right];
            
            //if the sum is found
            if(sum == k)
                return true;
            
            //decide the movement of left/right
            if(sum < k)
                left++;
            else
                right--;
            
        }
        
        return false;
        
    }
};