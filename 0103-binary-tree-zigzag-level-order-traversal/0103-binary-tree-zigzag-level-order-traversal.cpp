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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)return{};
        
        vector<vector<int>> v;
        
        queue<TreeNode*> que;
        que.push(root);
        
        bool directionLeft = true;
        
        while(!que.empty()){
            
            int len = que.size();
            vector<int> ele(len,0);
            
            for(int i = 0;i<len;i++){
                
                TreeNode* temp = que.front();
                que.pop();
                
                if(directionLeft)
                    ele[i] = temp->val;
                else
                    ele[len-1-i] = temp->val;
                
                if(temp->left)que.push(temp->left);
                
                if(temp->right)que.push(temp->right);
            }
            v.push_back(ele);
            directionLeft = !directionLeft;
            
        }
        
        return v;
        
    }
};