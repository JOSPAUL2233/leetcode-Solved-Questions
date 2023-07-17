class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();//matrix is of n x n size.
        
        //create an axtra array where the rotated array will be stored.
        vector<vector<int>> rotated(matrix.size(),vector<int> (matrix[0].size(),0));   
        
        //traverse throught the matrix and store the index accordingly in the rotated array
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<n;j++){
                rotated[j][n-1-i] = matrix[i][j];
            }
            
        }
        
        //allocate the rotated array into the matrix
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<n;j++){
                matrix[i][j] = rotated[i][j];   
            }
            
        }
        
        
        
    }
};