class Solution {
    
    void findPaths(vector<vector<int>> graph,vector<int> &path,vector<vector<int>> &ans,
                   unordered_map<int,bool> &visited,int source ,int destination){
        
        
        if(source == destination){
            
            ans.push_back(path);
            
        }
        
        for(int i = 0;i<graph[source].size();i++){
            
            int node = graph[source][i];
            
            if(!visited[node]){
                
                
                path.push_back(node);
                visited[node] = true;
                
                findPaths(graph,path,ans,visited,node,destination);
                
                visited[node] = false;
                path.pop_back();
                
            }
            
        }
        
                
        
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int source = 0;
        int destination = graph.size()-1;
        
        vector<vector<int>> ans;
        
        vector<int> path;
        
        unordered_map<int,bool> visited;
        
        visited[source] = true;
        path.push_back(source);
        
        findPaths(graph,path,ans,visited,source,destination);
        
        return ans;
        
        
    }
};