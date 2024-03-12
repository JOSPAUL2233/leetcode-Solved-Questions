class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>>adj[n];
        
        for(auto it:roads){
            
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        
        pq.push({0,0});
        
        //maintain a dist(minDist) array and ways(number of ways to reach at that node in shortest dist) array
        vector<long long >minDist(n,1e15),ways(n,0);
        ways[0]=1;
        minDist[0]=0;
        
        int mod=(int)1e9+7;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            long long dist = pq.top().first;
            
            pq.pop();
            
            for(auto it:adj[node]){
                
                int adjNode=it.first;
                long long adjW=it.second;
                
                //found new shortest path
                if(dist+adjW < minDist[adjNode]){
                    
                    minDist[adjNode]=dist+adjW;
                    pq.push({dist+adjW,adjNode});
                    
                    ways[adjNode]=ways[node];//store the number of ways
                    
                }else if(dist + adjW ==minDist[adjNode]){
                    
                    //found one more shortest path
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;//add up number of ways
                    
                }
            }
        }

        return ways[n-1]%mod;
        
    }
};