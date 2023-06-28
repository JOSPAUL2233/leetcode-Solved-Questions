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
    
    void solve(TreeNode* root,vector<vector<int>> &ans){
        
        if(root == NULL)
            return ;
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        while(!que.empty()){
            
            int length = que.size();
            vector<int> temp;
            
            for(int i = 0;i<length;i++){
                
                TreeNode* top = que.front();
                que.pop();
                
                temp.push_back(top->val);
                
                if(top->left)
                        que.push(top->left);
                if(top->right)
                        que.push(top->right);
                
            }
            
            ans.push_back(temp);
            
        }
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        //get the ans in top-down direction
        solve(root,ans);
        
        //reverse the ans
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};