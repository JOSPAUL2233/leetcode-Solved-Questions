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
    
    void solve(TreeNode* root,int target,vector<int> path,int &count){
        
        if(root == NULL)
            return;
        
        //push the current node into the path
        path.push_back(root->val);
        
        //explore all routes(ie. left and right)
        solve(root->left,target,path,count);
        solve(root->right,target,path,count);
        
        //starting from the back, check for targetSum
        long sum = 0;
        for(int i = path.size()-1;i>=0 ;i--){
            
            sum += path[i];
            
            if(sum == target)
                count++;
            
        }
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        //make a vector to keep a track of the path
        vector<int> path;
        
        //make a count to count the targetSum
        int count = 0;
        
        solve(root,targetSum,path,count);
        
        return count;
        
    }
};