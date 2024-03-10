class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> minDist(row,vector<int>(col,INT_MAX));
        
        //min heap
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        //del-r and del-c for iterating through 4-neibours
        int delRow[4] = {0,-1,0,+1};
        int delCol[4] = {+1,0,-1,0};
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            int dist = p.first;
            int r = p.second.first;
            int c = p.second.second;
            
            if(r==row-1 && c==col-1)
                return dist;
            
            for(int i = 0;i<4;i++){
                
                int nr = r+delRow[i];
                int nc = c+delCol[i];
                
                if(nr>=0 && nr<row && nc>=0 && nc<col){
                    
                    int effort = max(dist,abs(heights[nr][nc] - heights[r][c]));
                    
                    if(effort < minDist[nr][nc]){
                        minDist[nr][nc] = effort;
                        pq.push({effort,{nr,nc}});
                    } 
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};