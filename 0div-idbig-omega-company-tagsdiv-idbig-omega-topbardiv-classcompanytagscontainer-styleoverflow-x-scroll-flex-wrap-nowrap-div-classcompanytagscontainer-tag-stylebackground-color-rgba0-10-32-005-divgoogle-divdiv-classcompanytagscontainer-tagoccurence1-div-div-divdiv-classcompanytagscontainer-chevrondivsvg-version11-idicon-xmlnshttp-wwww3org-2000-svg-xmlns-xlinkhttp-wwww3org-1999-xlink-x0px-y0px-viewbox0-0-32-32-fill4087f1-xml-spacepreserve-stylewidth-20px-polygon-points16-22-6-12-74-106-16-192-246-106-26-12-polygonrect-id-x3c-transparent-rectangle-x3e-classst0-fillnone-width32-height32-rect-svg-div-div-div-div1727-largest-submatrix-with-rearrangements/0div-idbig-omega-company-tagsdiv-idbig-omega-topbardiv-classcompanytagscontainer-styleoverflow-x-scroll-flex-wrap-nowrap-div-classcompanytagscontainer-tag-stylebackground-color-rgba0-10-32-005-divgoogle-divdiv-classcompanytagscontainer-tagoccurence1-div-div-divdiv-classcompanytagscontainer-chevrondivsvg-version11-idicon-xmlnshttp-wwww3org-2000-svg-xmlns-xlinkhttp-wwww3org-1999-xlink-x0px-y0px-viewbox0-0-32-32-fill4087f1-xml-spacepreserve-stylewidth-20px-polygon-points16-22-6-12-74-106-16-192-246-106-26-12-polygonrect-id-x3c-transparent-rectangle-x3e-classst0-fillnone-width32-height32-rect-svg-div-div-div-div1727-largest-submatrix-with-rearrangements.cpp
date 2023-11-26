class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>> height(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i = 0;i<matrix.size();i++){
            
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
            
        }
        
        
        int maxArea = 0;

        for(int i = 0;i<height.size();i++){
            
            sort(height[i].begin(),height[i].end());
            
        }

        
        for(int i = 0;i<height.size();i++){
                        
            for(int j = 0;j<height[i].size();j++){
                
                int h = height[i][j];
                int w = height[i].size() - j;
                
                // cout<<h<<" "<<w<<endl;
                
                int area = h*w;
                maxArea = max(maxArea,area);
                
            }
            
        }
        
        return maxArea;
        
    }
};