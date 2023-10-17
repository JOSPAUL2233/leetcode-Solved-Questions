/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void storeParent(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        
        queue<TreeNode*> que;
        
        que.push(root);
        parent[root] = NULL;//keep parent of root node to be NULL
        
        while(!que.empty()){
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                TreeNode* node = que.front();
                que.pop();
                
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
    
    vector<int> getNodes(TreeNode* root,TreeNode* target,int k,map<TreeNode*,TreeNode*> parent){

        //keep a track of visited nodes
        map<TreeNode*,bool> visited;
        visited[target] = true;

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
                
                visited[node] = true;
                
                //k distance
                if(level == k)
                    ans.push_back(node->val);
                
                //upward direction
                if(parent[node] && !visited[parent[node]]){
                    
                    que.push(parent[node]);
                    // visited[parent[node]] = true;//update visited
                    
                }
                
                //left direction
                if(node->left && !visited[node->left]){
                    
                    que.push(node->left);
                    // visited[node->left] = true;//update visited
                    
                }
                
                //down direction
                if(node->right && !visited[node->right]){
                    
                    que.push(node->right);
                    visited[node->right] = true;
                    
                }
                
            }
            
            //increment level
            level++;
            
            //break if level crosses k
            if(level > k)
                break;
            
        }
        
        return ans;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //keep a track of parent
        map<TreeNode*,TreeNode*> parent;
        
        //do a BFS for storing parent
        storeParent(root,parent);
        
        //do a BFS for finding k distanced nodes
        vector<int> ans = getNodes(root,target,k,parent);
        
        return ans;
        
    }
};