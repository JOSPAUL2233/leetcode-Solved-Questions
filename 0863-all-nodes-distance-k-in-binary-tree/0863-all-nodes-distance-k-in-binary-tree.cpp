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
    
    void mapParent(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        
        //traverse level order
        
        queue<TreeNode*> que;
        que.push(root);
        
        parent[root] = NULL;
        
        while(!que.empty()){
            
            TreeNode* temp = que.front();
            que.pop();
                        
            if(temp->left){
                
                que.push(temp->left);
                parent[temp->left] = temp;
                
            }
            
            if(temp->right){
                
                que.push(temp->right);
                parent[temp->right] = temp;
                
            }   
        }
    }
    
    void solve(TreeNode* target,int k,map<TreeNode*,TreeNode*> parent,map<TreeNode*,bool> &visited, vector<int> &ans){
        
        if(target == NULL)
            return;
        
        if(k == 0 && !visited[target]){
            ans.push_back(target->val);
            return;
        }
        
        visited[target] = true;
                
        if(!visited[target->left])
            solve(target->left,k-1,parent,visited,ans);
        
        if(!visited[target->right])
            solve(target->right,k-1,parent,visited,ans);
        
        if(!visited[parent[target]])
            solve(parent[target],k-1,parent,visited,ans);
        
        visited[target] = false;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        //keep a track of paret nodes and find the targetNode
        map<TreeNode*,TreeNode*> parent;
        
        mapParent(root,parent);
        
        map<TreeNode*,bool> visited;
        
        //find the answer nodes
        solve(target,k,parent,visited,ans);
        
        return ans;
        
    }
};