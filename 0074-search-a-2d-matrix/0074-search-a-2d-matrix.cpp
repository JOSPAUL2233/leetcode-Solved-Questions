class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //BINARY SEARCH
        
        //iterate form 0 till n*m considering 2d matrix as a 1d matrix
        
        int rowMax = matrix.size();
        int colMax = matrix[0].size();
        
        int n = rowMax * colMax;
        
        int start = 0;
        int end = n - 1;
        
        while(start <= end){
            
            
            int mid = start + (end - start)/2;
            
            int row = mid / colMax;
            int col = mid % colMax;
            
            if(matrix[row][col] == target)
                return true;
            
            //shrink the search space
            if(matrix[row][col] > target){
                
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return false;
        
    }
};