class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxArea = 0;

        vector<pair<int, int>> prevHeights;
        
        for (int r = 0; r < m; r++) {

            vector<pair<int,int>> heights;
            
            //mark all the row elements as not visited
            vector<bool> visited(n, false);

            for (auto p : prevHeights) {
                
                int c = p.second;//gives col
                int h = p.first;//gives height
                
                //update  if there is a valid height at r,c (ie.1)
                if (matrix[r][c] == 1) {
                    
                    //update the current height along with it's col and mark it as visited
                    heights.push_back({h + 1, c});
                    visited[c] = true;
                    
                }
                
            }

            
            for (int c = 0; c < n; c++) {
                
                //update the height if it is not updated early and it is a valid height
                if (!visited[c] && matrix[r][c] == 1) {
                    
                    heights.push_back({1, c});
                    
                }
                
            }
			

            for (int i = 0; i < heights.size(); i++) {
                
                int h = heights[i].first;
                int w = i+1;

                int area = h*w;
                maxArea = max(maxArea,area);
                
            }
            
            prevHeights = heights;
            
        }

        return maxArea;
        
    }
};