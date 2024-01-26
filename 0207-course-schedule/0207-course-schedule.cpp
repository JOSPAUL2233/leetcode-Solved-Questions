class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        //if there is a cycle, we cannot take all the courses.
        //we can solve this using topo sort algo
        
        //first make graph
        vector<int> adj[n];
        
        for(int i = 0;i<prerequisites.size();i++){
            
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            
            adj[from].push_back(to);
            
        }
        
        //go for topo algo
        
        //get indegree of all the nodes
        vector<int> indegree(n,0);
        
        for(int i = 0;i<n;i++){
            
            for(int node : adj[i])
                indegree[node]++;
            
        }
        
        queue<int> que;
        int count = 0;
        
        //push all zero indegree nodes
        for(int i = 0;i<indegree.size();i++)
            if(indegree[i] == 0)
                que.push(i);
        
        //get into loop
        while(!que.empty()){
            
            int node = que.front();
            que.pop();
            
            //keep track of size of topo
            count++;
            
            for(int i : adj[node]){
                
                indegree[i]--;
                
                if(indegree[i] == 0)
                    que.push(i);
                
            }
            
        }
        
        if(count == n)
            return true;
        else
            return false;
        
    }
};