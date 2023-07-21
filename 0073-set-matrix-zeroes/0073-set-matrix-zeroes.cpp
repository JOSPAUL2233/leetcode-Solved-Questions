class Solution {
public:

    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        //make two arrays to keep the track of the rows and cols
        //which should be filled with zeros
        vector<int> zeroRow(row,0);
        vector<int> zeroCol(col,0);
        
        //iterate through the matrix
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                //if the current element is zero
                if(matrix[i][j] == 0){
                    
                    //update zeroRow and zeroCol
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                    
                }
                
            }
            
        }
        
        //replace zeroRow and zeroCol elements to zeros
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(zeroRow[i] == 1 || zeroCol[j] == 1){
                    
                    matrix[i][j] = 0;
                    
                }
                
            }
            
        }
        
    }
};