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
    vector<int> largestValues(TreeNode* root) {
        
        //edge case
        if(root == NULL)
            return {};
        
        //level order traversal or BFS
        vector<int> ans;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            
            int size = que.size();
            
            int maxi = INT_MIN;
            for(int i = 0;i<size;i++){
                
                TreeNode* node = que.front();
                que.pop();
                
                maxi = max(maxi,node->val);
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
                
            }
            
            ans.push_back(maxi);
            
        }
        
        return ans;
        
    }
};