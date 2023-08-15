class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //apply binary search
        
        //INTUITION --> left side will contain smaller elements,
        //bottom side will contain higher elements
        
        int rowMax = matrix.size();
        int colMax = matrix[0].size();
        
        // start from right top
        int row = 0;
        int col = colMax - 1;
        
        while(row < rowMax && col >= 0){
            
            //if the target is found
            if(matrix[row][col] == target)
                return true;
            
            //shrink the search space
            if(matrix[row][col] < target){
                
                row++;
                
            }else{
                
                col--;
                
            }
            
        }
        
        return false;
        
    }
};