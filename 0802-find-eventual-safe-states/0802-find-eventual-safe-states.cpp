class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        //reverse the nodes
        int V = graph.size();
        
        vector<vector<int>> rev(V);
        
        for(int i = 0;i<V;i++){
            
            for(auto node : graph[i]){
                
                rev[node].push_back(i);
                
            }
            
        }
        
        //do topo sort
        
        vector<int> indegree(V,0);
        
        for(int i = 0;i<V;i++){
            
            for(auto node : rev[i]){
                indegree[node]++;
            }
            
        }
        
        
        //push all the nodes with indegree zero
        queue<int> que;
        vector<int> ans;
        
        for(int i = 0;i<V;i++)
            if(indegree[i] == 0)
                que.push(i);
            
        
        while(!que.empty()){
            
            int ele = que.front();
            que.pop();
            
            for(auto i : rev[ele]){
                
                indegree[i]--;
                
                if(indegree[i] == 0){
                    que.push(i);
                }
                
            }
            
        }
        
        for(int i = 0;i<indegree.size();i++)
            if(indegree[i] == 0)
                ans.push_back(i);
        
        return ans;
        
    }
};