class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        int per = 0;
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                
                if(grid[i][j]==1){
                    
                    if(j-1 < 0 || grid[i][j-1]!=1)//left
                        per++;
                    
                    if(j+1 >= col || grid[i][j+1]!=1)//right
                        per++;
                    
                    if(i-1 < 0 || grid[i-1][j]!=1)//up
                        per++;
                    
                    if(i+1 >= row || grid[i+1][j]!=1)//down
                        per++;
                }
                
            }
        }
        
        return per;
        
    }
};