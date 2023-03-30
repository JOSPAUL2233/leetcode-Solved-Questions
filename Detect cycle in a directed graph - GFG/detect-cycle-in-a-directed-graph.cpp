//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool dfsCheck(int i,vector<int> adj[],unordered_map<int,bool> &visited,
                        unordered_map<int,bool> &path){
                            
                                    
            for(auto j : adj[i]){
                
                // cout<<"visited["<<j<<"] = "<<i<<","<<visited[j]<<endl;
                // cout<<"path["<<j<<"] = "<<i<<","<<path[j]<<endl;

                
                if(!visited[j]){ // if not visited, go to that node
                    
                    visited[j] = true;
                    path[j] = true;
                    bool cycle = dfsCheck(j,adj,visited,path);
                    path[j] = false;
                    
                    if(cycle)return true;
                    
                }else{
                    
                    if(path[j])
                        return true;
                    // else // if visited and not in the same path, don't check for
                    //     // further nodes since we have done it already
                    //     break;
                }
                
            }
             
            return false;                           
                            
        }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        
        //make two hashmap - visited,path
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> path;
        
        for(int i = 0;i<V;i++){
            
            if(!visited[i]){
                visited[i] = true;
                path[i] = true;
                bool cycle = dfsCheck(i,adj,visited,path);
                
                if(cycle)return true;
                path[i] = false;
                
            }
            
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends