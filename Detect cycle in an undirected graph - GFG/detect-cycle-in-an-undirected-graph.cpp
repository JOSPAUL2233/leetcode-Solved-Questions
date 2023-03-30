//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool bfsCheck(int i,vector<int> adj[],unordered_map<int,bool> &visited,
                    unordered_map<int,int> &parent){
        
            queue<int> que;
            que.push(i);
            
            while(!que.empty()){
                
                int front = que.front();
                que.pop();
                
                for(auto j : adj[front]){
                    
                    if(!visited[j]){
                        
                        //if not visited, insert it in queue
                        //and update visited and parent
                        visited[j] = true;
                        parent[j] = front;
                        que.push(j);
                        
                    }else if(visited[j] && (parent[front] != j)){
                        
                        //if visited and parent is not front
                        return true;

                    }
                
                    //ignore if it is pointing to it's parent
                    
                }
                
            }
            
            return false;
        
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        //make two maps - one for parent and other for visited
        
        unordered_map<int,int> parent;
        unordered_map<int,bool> visited;
        
        bool ans = false;
        
        for(int i = 0;i<V;i++){
            
            if(!visited[i]){
                visited[i] = true;
                parent[i] = -1;
                ans = bfsCheck(i,adj,visited,parent);
                
            }
            
            if(ans == true)return true;
            
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends