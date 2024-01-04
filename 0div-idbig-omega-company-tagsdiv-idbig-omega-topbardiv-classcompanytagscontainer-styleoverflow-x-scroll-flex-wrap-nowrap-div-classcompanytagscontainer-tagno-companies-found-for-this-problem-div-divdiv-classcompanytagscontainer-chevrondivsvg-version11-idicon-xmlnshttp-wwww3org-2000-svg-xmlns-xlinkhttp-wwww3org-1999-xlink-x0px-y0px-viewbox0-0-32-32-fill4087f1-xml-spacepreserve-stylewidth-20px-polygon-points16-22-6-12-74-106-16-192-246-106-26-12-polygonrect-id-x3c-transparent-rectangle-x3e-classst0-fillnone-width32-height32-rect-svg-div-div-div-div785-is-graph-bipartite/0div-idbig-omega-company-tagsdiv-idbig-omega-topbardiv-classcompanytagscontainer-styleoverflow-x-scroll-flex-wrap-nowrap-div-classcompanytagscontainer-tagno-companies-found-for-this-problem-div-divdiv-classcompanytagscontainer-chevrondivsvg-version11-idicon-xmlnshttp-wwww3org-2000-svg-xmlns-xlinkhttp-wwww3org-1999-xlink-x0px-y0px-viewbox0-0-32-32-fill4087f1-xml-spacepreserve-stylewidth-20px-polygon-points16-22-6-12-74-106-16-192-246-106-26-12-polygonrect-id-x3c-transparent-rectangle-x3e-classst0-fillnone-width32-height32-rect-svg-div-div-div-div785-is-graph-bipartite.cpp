class Solution {
public:
    
    bool checkBipartite(vector<vector<int>> graph,vector<int> &colors, int n,int V){
        
        queue<int> que;
        que.push(n);
        
        while(!que.empty()){
            
            int node = que.front();
            que.pop();
            
            for(int i : graph[node]){
                
                //if it is uncolored, then color the opposite color of the current node
                if(colors[i] == -1){
                    
                    colors[i] = !colors[node];
                    que.push(i);
                    
                    
                }else if(colors[i] == colors[node]){
                    
                    //if it is colored but same as that of current node's color
                    return false;
                    
                }
                                
            }
            
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
                
        //we will solve it using BFS
        
        //maintain a vector of colors or (types of A and B)
        //let's keep three states -1 (uncolored), then 1 and 0 stating two colors or groups(A and B)
        
        int V = graph.size();
        vector<int> colors(V,-1);
        
        //iterate through all the nodes since there can be multiple componants
        for(int i = 0;i<V;i++){
            
            if(colors[i] == -1){
                
                colors[i] == 0;
                
                if(!checkBipartite(graph,colors,i,V))
                    return false;
                
            }
            
        }
        
        return true;
        
    }
};