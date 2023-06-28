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
        
        //edge case
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> que;
        bool leftToRight = true;
        
        que.push(root);
        
        while(!que.empty()){
            
            int size = que.size();
            vector<int> vec(size,0);
            
            for(int i = 0;i<size;i++){
                
                //take out the front element
                TreeNode* temp = que.front();
                que.pop();
                
                //check for direction and store accordingly
                if(leftToRight){
                    vec[i] = temp->val;
                }else{
                    vec[size-1-i] = temp->val;
                }
            
                //insert left and right into queue if exists
                if(temp->left)
                    que.push(temp->left);
                
                if(temp->right)
                    que.push(temp->right);
            }
            
            //store the vec to ans and change the direction
            //for the next for next iteration
            
            ans.push_back(vec);
            leftToRight = !leftToRight;
            
        }
        
        return ans;
    }
};