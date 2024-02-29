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
    bool isEvenOddTree(TreeNode* root) {
                
        //BFS
        queue<TreeNode*> que;
        que.push(root);
        
        bool isEven = true;
        
        while(!que.empty()){
            
            int size = que.size();
            int prev = -1;
            
            for(int i = 0;i<size;i++){
                
                TreeNode* curr = que.front();
                que.pop();
                
                if(isEven){
                    
                    if(prev == -1 && (curr->val&1)==0)
                        return false;
                    
                    if(prev != -1 && (prev>=curr->val || (curr->val&1) == 0))
                        return false;
                    else
                        prev = curr->val;
                    
                }else{
                    
                    if(prev == -1 && curr->val&1)
                        return false;
                    
                    if(prev != -1 && (prev<=curr->val || curr->val&1))
                        return false;
                    else
                        prev = curr->val;
                    
                }
                
                if(curr->left)
                    que.push(curr->left);
                
                if(curr->right)
                    que.push(curr->right);
                
            }
            
            isEven = !isEven;
            
        }
        
        return true;
        
    }
};