class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        vector<int> prev;
        
        prev.push_back(points[0][0]);
        prev.push_back(points[0][1]);
        
        int count = 0;
        
        for(int i = 1;i<points.size();i++){
            
            //find the smallest diff which will be the diagonal distance
            int xDist = abs(prev[0] - points[i][0]);
            int yDist = abs(prev[1] - points[i][1]);
            
            int totalDist = max(xDist,yDist);
            
            count += totalDist;
            
            //update the prev
            prev[0] = points[i][0];
            prev[1] = points[i][1];
            
        }
        
        return count;
        
    }
};