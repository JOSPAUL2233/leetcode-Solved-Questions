class Solution {
public:
    
    void bfs(vector<vector<int>> isConnected,int city,vector<int> &visited){
        
        queue<int> que;
        que.push(city);
        
        while(!que.empty()){
            
            int node = que.front();
            que.pop();
                            
            for(int i = 0;i<isConnected[node].size();i++){

                if(isConnected[node][i] == 1 && !visited[i]){
                    
                    visited[i] = 1;
                    que.push(i);
                        
                }
                    
            }
                
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
                
        //make a visited array
        vector<int> visited(isConnected.size(),0);
        
        int count = 0;
        
        for(int i = 0;i<isConnected.size();i++){
            
            if(!visited[i]){
                
                visited[i] = 1;
                bfs(isConnected,i,visited);
                count++;
            }
        }
        
        return count;
        
    }
};