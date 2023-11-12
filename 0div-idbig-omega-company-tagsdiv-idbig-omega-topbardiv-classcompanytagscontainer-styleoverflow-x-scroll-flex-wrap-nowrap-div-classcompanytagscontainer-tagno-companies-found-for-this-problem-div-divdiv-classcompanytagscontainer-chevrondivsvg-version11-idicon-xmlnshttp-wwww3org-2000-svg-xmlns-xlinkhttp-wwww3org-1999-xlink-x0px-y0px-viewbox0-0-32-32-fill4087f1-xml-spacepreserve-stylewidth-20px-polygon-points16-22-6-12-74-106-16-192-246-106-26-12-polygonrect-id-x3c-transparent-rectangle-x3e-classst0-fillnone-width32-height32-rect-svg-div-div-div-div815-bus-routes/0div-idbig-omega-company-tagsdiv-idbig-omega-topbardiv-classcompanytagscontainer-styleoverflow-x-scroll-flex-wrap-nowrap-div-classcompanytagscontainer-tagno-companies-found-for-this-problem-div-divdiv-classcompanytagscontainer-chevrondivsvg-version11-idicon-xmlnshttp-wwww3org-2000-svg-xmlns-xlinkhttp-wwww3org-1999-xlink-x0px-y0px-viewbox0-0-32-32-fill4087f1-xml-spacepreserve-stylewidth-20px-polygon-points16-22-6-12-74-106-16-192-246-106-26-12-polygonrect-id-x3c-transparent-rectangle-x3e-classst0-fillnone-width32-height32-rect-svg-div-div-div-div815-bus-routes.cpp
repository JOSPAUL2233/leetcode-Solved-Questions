class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n = routes.size(); 
        
        if(S == T || n == 0) return 0;
        
        unordered_map<int,vector<int>> stops;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<routes[i].size();j++){
                
                int curStop = routes[i][j];
                int curBus = i;
                stops[curStop].push_back(curBus); 
            }
        }
        return helper(routes,stops,S,T);
    }
    
    int helper(vector<vector<int>>& routes, unordered_map<int,vector<int>>& stops, int src, int dest) {
        
        
        if(src == dest) return 0;
        
        unordered_map<int,bool> visitedStop; 
        for(auto itr=stops.begin();itr!=stops.end();itr++){
            visitedStop[itr->first]=false; 
        }
        vector<bool> visitedBus(routes.size(), false); 
        queue<pair<int,int>> q;
        q.push({src,0});
        visitedStop[src] = true;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int cur_stop = front.first;
            int count = front.second;
            if(cur_stop == dest) return count;
            vector<int> bus_options = stops[cur_stop]; 
            for(int i=0;i<bus_options.size();i++){
                int cur_bus = bus_options[i];
                if(visitedBus[cur_bus]) continue; 
                else {
                    vector<int> nextStops = routes[cur_bus];
                    
                    for(int j=0;j<nextStops.size();j++){
                        
                        int nextStop = nextStops[j];
                        
                        if(visitedStop[nextStop]) continue;
                        
                        else{
                            q.push({nextStop, count+1});
                            visitedStop[nextStop] = true;
                        }
                    }
                    
                    visitedBus[cur_bus] = true;
                }
            }
        }
        
        return -1;
    }
};