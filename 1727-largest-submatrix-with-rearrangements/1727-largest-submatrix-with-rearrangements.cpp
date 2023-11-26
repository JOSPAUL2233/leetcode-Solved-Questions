class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        vector<int> prev(matrix[0].size(),0);
        vector<int> curr(matrix[0].size(),0);
        // vector<int> sorted(matrix.size(),0);
        
        int maxArea = 0;
        
        for(int i = 0;i<matrix.size();i++){
                
            //finding heights of curr row
            for(int j = 0;j<matrix[0].size();j++){
                                
                if(matrix[i][j] == 0){
                    curr[j] = 0;
                }else{
                    
                   if(i == 0){//first row
                       curr[j] = 1;
                   }else{
                       curr[j] = 1 + prev[j];
                   }
                    
                }                
                
            }
            
            //store the current row in prev row
            prev = curr;
            
            //extract the current row and sort it
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