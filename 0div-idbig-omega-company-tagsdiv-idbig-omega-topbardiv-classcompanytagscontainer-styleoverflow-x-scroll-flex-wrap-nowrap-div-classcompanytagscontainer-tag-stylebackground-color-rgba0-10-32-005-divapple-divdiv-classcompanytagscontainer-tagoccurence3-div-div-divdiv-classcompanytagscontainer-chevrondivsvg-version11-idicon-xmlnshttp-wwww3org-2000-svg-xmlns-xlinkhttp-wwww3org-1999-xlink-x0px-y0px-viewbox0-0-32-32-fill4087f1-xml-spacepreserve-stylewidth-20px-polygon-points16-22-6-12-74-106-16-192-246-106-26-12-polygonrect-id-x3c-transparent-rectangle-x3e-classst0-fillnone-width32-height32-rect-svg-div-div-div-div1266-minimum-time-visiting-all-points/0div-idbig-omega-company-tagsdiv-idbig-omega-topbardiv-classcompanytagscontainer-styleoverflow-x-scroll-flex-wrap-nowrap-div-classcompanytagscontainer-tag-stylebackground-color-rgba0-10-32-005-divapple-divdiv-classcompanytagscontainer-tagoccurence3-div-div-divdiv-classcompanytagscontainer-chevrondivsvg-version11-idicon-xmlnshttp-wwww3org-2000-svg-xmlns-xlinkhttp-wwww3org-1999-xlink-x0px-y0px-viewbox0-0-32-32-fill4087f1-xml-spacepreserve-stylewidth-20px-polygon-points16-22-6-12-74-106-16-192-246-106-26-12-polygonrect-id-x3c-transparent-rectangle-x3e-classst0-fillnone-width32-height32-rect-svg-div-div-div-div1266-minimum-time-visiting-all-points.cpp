class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        vector<int> prev;
        
        prev.push_back(points[0][0]);
        prev.push_back(points[0][1]);
        
        int count = 0;
        
        for(int i = 1;i<points.size();i++){
            
            //find the smallest diff which will be the diagonal distance
            int diffx = abs(points[i][0] - prev[0]);
            int diffy = abs(points[i][1] - prev[1]);
            
            int diaDist = min(diffx,diffy);
            int normalDist = diffx + diffy;    
            
            int dist = normalDist - diaDist;
            
            count += dist;
            
            //update the prev
            prev[0] = points[i][0];
            prev[1] = points[i][1];
            
        }
        
        return count;
        
    }
};