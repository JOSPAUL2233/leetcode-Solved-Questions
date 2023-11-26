class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>> height(matrix.size(),vector<int>(matrix[0].size(),0));
        
        int maxArea = 0;
        
        for(int i = 0;i<matrix.size();i++){
                
            //finding heights
            for(int j = 0;j<matrix[0].size();j++){
                                
                if(matrix[i][j] == 0){
                    height[i][j] = 0;
                }else{
                    
                   if(i == 0){
                       height[i][j] = 1;
                   }else{
                       height[i][j] = 1 + height[i-1][j];
                   }
                    
                }                
                
            }
            
            //extract the current row and sort it
            vector<int> curr = height[i];
            
            //get entire row of heigths sorted
            sort(curr.begin(),curr.end());

            //get the answer from the sorted row
            for(int j = 0;j<curr.size();j++){
                
                int h = curr[j];
                int w = curr.size() - j;
                                
                int area = h*w;
                maxArea = max(maxArea,area);
                
            }
            
        }

        return maxArea;
        
    }
};