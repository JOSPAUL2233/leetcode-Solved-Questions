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
        
        queue<TreeNode*> q;
        
        if(root == NULL)
            return {};
        
        q.push(root);
        
        vector<vector<int>> ans;
        
        while(!q.empty()){
            
            int len = q.size();
            vector<int> vec;
            
            for(int i = 0;i<len;i++){
                
                TreeNode* temp = q.front();
                q.pop();
                
                vec.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
            }
            
            ans.push_back(vec);
        }
        
        return ans;
    }
};