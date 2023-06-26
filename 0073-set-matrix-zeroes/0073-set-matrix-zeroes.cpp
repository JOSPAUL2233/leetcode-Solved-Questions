class Solution {
public:
    
    void makeZeroes(vector<vector<int>>& matrix, int i,int j,int row,
                                int col,map<pair<int,int>,bool>& visited){
        
        //up
        int up_i = i-1;
        int up_j = j;
        
        //down
        int down_i = i+1;
        int down_j = j;
        
        //left
        int left_i = i;
        int left_j = j-1;
        
        //right
        int right_i = i;
        int right_j = j+1;
        
        //filling zeros in this loop
        
        while(up_i >= 0 || down_i < row || left_j >= 0 || right_j < col){
            
            //within the limit(same for all)
            if(up_i>=0){
                
                //currently element is not zero(same for all)
                if(matrix[up_i][up_j] != 0){
                    
                    visited[{up_i,up_j}] = true;
                    matrix[up_i][up_j] = 0;
                    
                }
                
                up_i--;
                
            }
            
            if(down_i<row){
                
                if(matrix[down_i][down_j] != 0){
                    
                    visited[{down_i,down_j}] = true;
                    matrix[down_i][down_j] = 0;
                    
                }
                
                down_i++;
                
            }
            
            if(left_j >= 0){
                
                if(matrix[left_i][left_j] != 0){
                    
                    visited[{left_i,left_j}] = true;
                    matrix[left_i][left_j] = 0;
                    
                }
                
                left_j--;
                
            }
            
            if(right_j < col){
                
                if(matrix[right_i][right_j] != 0){
                    
                    visited[{right_i,right_j}] = true;
                    matrix[right_i][right_j] = 0;
                    
                }
                
                right_j++;
                
            }
            
        }
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        map<pair<int,int>,bool> visited;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(matrix[i][j] == 0 && !visited[{i,j}]){
                    
                    makeZeroes(matrix,i,j,row,col,visited);
                    visited[{i,j}] = true;
                    
                }
                
            }
            
        }
        
        
//          for(int i = 0;i<row;i++){
            
//             for(int j = 0;j<col;j++){
                
//                 cout<<visited[{i,j}]<<" ";
//             }cout<<endl;
//          }
    }
};