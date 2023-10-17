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
    
    void storeParent(TreeNode* root,map<TreeNode*,TreeNode*> &parent,int val,TreeNode* &target){
        
        queue<TreeNode*> que;
        
        que.push(root);
        parent[root] = NULL;//keep parent of root node to be NULL
        
        while(!que.empty()){
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                TreeNode* node = que.front();
                que.pop();
                
                //check for target node
                if(node->val == val)
                    target = node;
                
                //check for left child
                if(node->left){
                    
                    parent[node->left] = node;//parent update
                    que.push(node->left);
                    
                }
                
                //check for right child
                if(node->right){
                    
                    parent[node->right] = node;//parent update
                    que.push(node->right);
                    
                }
                
            }
            
        }
        
    }
    
    int getMinTime(TreeNode* target, map<TreeNode*, TreeNode*> parent){
        
        //keep a track of visited nodes
        map<TreeNode*,bool> visited;

        queue<TreeNode*> que;
        que.push(target);
        
        //counts the levels
        int level = 0;
        vector<int> ans;
        
        while(!que.empty()){
            
            int size = que.size();
                        
            for(int i = 0;i<size;i++){
                
                TreeNode* node = que.front();
                que.pop();
                
                //mark this node as visited
                visited[node] = true;
                
                //upward direction
                if(parent[node] && !visited[parent[node]])
                    que.push(parent[node]);
                                    
                //left direction
                if(node->left && !visited[node->left])
                    que.push(node->left);
                                    
                //down direction
                if(node->right && !visited[node->right])
                    que.push(node->right);                    
                
            }
            
            //increment level
            level++;
            
        }
        
        return level-1;
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        //do a BFS for storing parent and finding target in a single iteration
        map<TreeNode*,TreeNode*> parent;
        TreeNode* target;
        
        storeParent(root,parent,start,target);
        
        //do a BFS to find min time to burn tree
        int minTime = getMinTime(target,parent);
        
        return minTime;
        
    }
};