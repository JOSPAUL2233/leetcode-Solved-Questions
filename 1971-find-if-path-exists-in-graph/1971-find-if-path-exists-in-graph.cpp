class Solution {
    
    bool BFS(int source,vector<list<int>> adj ,int destination){
        
        queue<int> que;
        
        unordered_map<int,bool> visited;
        
        for(int i = 0;i<adj.size();i++){
            
            visited[i] = false;
            
        }
        
        
        que.push(source);
        visited[source] = true;
        
        while(!que.empty()){
            
            int front = que.front();
            que.pop();
            
            if(front == destination)return true;
            
            //insert all the neibours of front
            
            for(auto i : adj[front]){

                
                if(!visited[i]){
                    
                    que.push(i);
                    visited[i] = true;
                    cout<<i<<" ";
                    
                }
                
            }cout<<endl;
            
        }
        
        return false;
        
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        if(n==1 && (source == 0 && destination ==0))return true;
        
        // making adjacent list
        
        vector<list<int>> adj(n);
        
        
        for(int i = 0;i<edges.size();i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        // applying BFS
        
        bool ans =  BFS(source,adj,destination);
        
        return ans;
        
                
    }
};