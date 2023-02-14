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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //base case
        if(root==NULL)return {};
        
        queue<TreeNode*> que;
        que.push(root);
        
        vector<vector<int>> ans;
        
        while(!que.empty()){
           
            int len = que.size();
            vector<int> v;
            TreeNode* temp;
            
            for(int i = 0;i<len;i++){
                
                temp = que.front();
                que.pop();
                
                v.push_back(temp->val);
                 
                if(temp->left)que.push(temp->left);
                
                if(temp->right)que.push(temp->right);
                
            }
            ans.push_back(v);
            
        }
        
        
        return ans;
        
        
    }
};