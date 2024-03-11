class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //make adj lists
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<flights.size();i++){
            
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
        }
        
        vector<int> minDist(n,INT_MAX);
        
        queue<pair<int,pair<int,int>>> que;
        que.push({0,{src,0}}); //cost,node,steps
        
        minDist[src] = 0;
        
        while(!que.empty()){
            
            auto p = que.front();
            que.pop();
            
            int cost = p.first;
            int node = p.second.first;
            int stops = p.second.second;
            
            // cout<<cost<<" "<<node<<" "<<steps<<endl;
            
            if(stops > k)
                continue;
                        
            for(auto it : adj[node]){
                
                if(cost + it.second < minDist[it.first]){
                    minDist[it.first] = cost+it.second;
                    que.push({cost+it.second,{it.first,stops+1}});
                }
                
            }
            
        }
        
        if(minDist[dst]==INT_MAX)
            return -1;
        else
            return minDist[dst];
    }
};