class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    
        
        //make adjacency list    
        vector<list<int>> adj(n);
        
        for(int i = 0;i<edges.size();i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            //since it is directed graph
            adj[u].push_back(v);
        }
        
        
        //IDENTIFY THE VERTICES USING A HASHMAP
        unordered_map<int,bool> vertices;
        for(int i = 0;i<n;i++){      
            for(auto j : adj[i]){              
                vertices[j] = true;   
            }  
        }
        
        vector<int> ans;
        
        //extract the vertices
        for(int i = 0;i<n;i++){
            
            if(!vertices[i])ans.push_back(i);
            
        }
        
        return ans;
        
    }
};