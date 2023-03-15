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
    bool isCompleteTree(TreeNode* root) {
        
        //---- LEVEL ORDER TRAVERSAL
        
        queue<TreeNode*> que;
        
        bool ans = false;
        
        que.push(root);
        
        while(!que.empty()){
            
            TreeNode* temp = que.front();
            que.pop();
            
            if(temp==NULL){
                ans = true;
            }else{
                
                if(ans)return false;
                que.push(temp->left);
                que.push(temp->right);
                
            }
            
            
        }
        
        return true;
        
    }
};