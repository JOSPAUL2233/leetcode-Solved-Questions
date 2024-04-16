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
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
                
        //edge case
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        int d = 1;
        
        while(!que.empty()){
            
            if(d == depth-1)
                break;
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                TreeNode* n = que.front();
                que.pop();
                
                if(n->left)
                    que.push(n->left);
                
                if(n->right)
                    que.push(n->right);
                
            }
            
            d++;
            
        }
        
        int size = que.size();
        for(int i = 0;i<size;i++){
            
            TreeNode* node = que.front();
            que.pop();
                        
            //store left and right nodes
            TreeNode* leftn = node->left;
            TreeNode* rightn = node->right;
            
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            
            node->left->left = leftn;
            node->right->right = rightn;
            
        }
        
        return root;
        
    }
};