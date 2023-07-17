class Solution {
public:
    
    void reverse(vector<int> &matrix,int n){
        
        for(int i = 0;i < n/2;i++){
            swap(matrix[i] , matrix[n-1-i]);
        }
        
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        //Transpose the matrix
        for(int i = 0;i<n;i++){
            
            for(int j = i+1;j<n;j++){
                
                swap(matrix[i][j] , matrix[j][i]);
                
            }
            
        }
        
        //Reverse all the raws of the matrix
        for(int i = 0;i<n;i++){
            
            reverse(matrix[i],n);
            
        }
        
    }
};