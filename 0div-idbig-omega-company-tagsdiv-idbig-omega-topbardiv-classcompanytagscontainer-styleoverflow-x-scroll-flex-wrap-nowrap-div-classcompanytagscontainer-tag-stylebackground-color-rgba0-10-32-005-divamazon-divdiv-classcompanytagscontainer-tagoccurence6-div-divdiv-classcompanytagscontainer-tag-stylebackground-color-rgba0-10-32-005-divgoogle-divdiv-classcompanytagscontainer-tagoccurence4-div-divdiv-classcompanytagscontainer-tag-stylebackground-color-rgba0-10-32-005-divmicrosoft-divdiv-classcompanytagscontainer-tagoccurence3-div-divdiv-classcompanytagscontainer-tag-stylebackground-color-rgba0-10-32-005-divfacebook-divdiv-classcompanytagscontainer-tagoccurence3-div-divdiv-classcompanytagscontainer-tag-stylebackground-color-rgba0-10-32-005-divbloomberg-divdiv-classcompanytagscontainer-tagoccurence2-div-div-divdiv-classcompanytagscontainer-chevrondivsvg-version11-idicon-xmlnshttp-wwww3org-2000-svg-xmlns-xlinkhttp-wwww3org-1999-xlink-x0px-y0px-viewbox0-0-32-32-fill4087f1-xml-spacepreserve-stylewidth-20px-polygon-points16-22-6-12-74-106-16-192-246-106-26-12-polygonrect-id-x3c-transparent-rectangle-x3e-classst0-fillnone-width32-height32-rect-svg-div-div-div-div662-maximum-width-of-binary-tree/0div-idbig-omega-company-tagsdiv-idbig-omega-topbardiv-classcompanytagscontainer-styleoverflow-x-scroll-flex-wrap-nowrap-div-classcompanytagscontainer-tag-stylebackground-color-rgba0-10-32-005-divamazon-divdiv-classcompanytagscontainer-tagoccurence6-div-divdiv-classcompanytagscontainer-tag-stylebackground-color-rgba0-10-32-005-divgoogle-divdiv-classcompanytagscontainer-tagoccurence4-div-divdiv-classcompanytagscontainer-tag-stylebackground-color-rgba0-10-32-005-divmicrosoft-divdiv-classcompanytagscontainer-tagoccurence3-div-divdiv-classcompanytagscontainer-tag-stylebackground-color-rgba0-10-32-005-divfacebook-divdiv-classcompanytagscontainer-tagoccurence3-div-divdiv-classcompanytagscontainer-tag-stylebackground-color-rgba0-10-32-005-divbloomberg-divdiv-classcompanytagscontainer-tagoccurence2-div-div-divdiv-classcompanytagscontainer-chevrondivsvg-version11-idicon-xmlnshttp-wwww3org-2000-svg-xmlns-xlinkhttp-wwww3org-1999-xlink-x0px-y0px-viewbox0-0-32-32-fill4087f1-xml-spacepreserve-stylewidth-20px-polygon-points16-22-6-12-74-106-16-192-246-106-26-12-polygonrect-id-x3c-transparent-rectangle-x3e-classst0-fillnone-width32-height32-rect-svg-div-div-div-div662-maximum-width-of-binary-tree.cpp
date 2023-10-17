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
    int widthOfBinaryTree(TreeNode* root) {
        
        //edge case
        if(root == NULL)
            return 0;
        
        //LEVEL ORDER TRAVERSAL - calculating width in each level and storing max
        
        queue<pair<TreeNode*,long long>> que;
        que.push({root,0});
        
        int maxWidth = 0;
        
        while(!que.empty()){
            
            int size = que.size();
            
            //store first and last num value int current level
            int first = que.front().second;
            int last = que.back().second;
                
            //calculate width and store the max
            int width = last - first + 1;
            maxWidth = max(maxWidth, width);
            
            for(int i = 0;i<size;i++){
                
                //extract contents from queue
                TreeNode* node = que.front().first;
                long long num = que.front().second - first;//to make num starting from zero
                que.pop();
                
                //if left child exists
                if(node->left)
                    que.push({node->left,(long long) num*2 + 1});
                
                //if right child exists
                if(node->right)
                    que.push({node->right,(long long) num*2 + 2});
                
            }
            
        }
        
        return maxWidth;
        
    }
};