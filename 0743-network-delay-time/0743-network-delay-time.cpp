class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //make adj lists for graph nodes
        vector<pair<int,int>> adj[n+1];
        
        //make minDist;
        vector<int> minDist(n+1,INT_MAX);
        minDist[0] = 0;//won't be using this
        
        for(auto it : times)
            adj[it[0]].push_back({it[1],it[2]});
        
        //do dijstra's algo
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        minDist[k] = 0;
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            int node = p.second;
            int time = p.first;
                        
            for(auto it : adj[node]){
                
                int n = it.first;
                int t = it.second;
                                
                if((time+t) < minDist[n]){
                    minDist[n] = time+t;
                    pq.push({time+t,n});
                }
                
            }
            
        }
        
        //take the max value
        int maxi = 0;
        
        for(int i = 1;i<=n;i++)maxi = max(maxi,minDist[i]);
        
        if(maxi == INT_MAX)
            return -1;
        else
            return maxi;
        
    }
};