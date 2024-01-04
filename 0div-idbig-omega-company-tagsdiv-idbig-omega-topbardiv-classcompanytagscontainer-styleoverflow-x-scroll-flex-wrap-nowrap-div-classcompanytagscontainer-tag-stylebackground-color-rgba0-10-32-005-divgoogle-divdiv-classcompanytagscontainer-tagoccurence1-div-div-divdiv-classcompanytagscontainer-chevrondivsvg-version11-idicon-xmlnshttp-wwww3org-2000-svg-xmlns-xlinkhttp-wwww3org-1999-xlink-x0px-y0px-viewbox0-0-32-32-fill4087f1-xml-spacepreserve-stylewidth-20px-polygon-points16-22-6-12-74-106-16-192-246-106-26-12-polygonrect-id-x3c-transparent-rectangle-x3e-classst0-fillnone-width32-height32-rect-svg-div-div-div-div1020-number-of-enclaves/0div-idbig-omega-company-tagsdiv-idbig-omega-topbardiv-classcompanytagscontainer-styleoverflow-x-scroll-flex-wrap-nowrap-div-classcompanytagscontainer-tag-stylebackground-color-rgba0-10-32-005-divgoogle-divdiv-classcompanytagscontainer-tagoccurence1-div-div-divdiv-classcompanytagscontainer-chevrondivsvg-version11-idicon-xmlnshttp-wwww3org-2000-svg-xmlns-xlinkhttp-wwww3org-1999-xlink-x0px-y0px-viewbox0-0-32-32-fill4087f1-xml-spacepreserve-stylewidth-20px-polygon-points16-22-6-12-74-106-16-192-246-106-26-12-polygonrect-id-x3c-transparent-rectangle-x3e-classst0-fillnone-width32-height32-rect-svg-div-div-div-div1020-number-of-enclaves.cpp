class Solution {
public:
    
    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,-1,0,+1};
    
    void dfsSol(vector<vector<int>> &grid,int r,int c){
        
        int row = grid.size();
        int col = grid[0].size();
        
        grid[r][c] = 0;
        
        //for for 4-neibours
        for(int i = 0;i<4;i++){
            
            int nRow = r+delRow[i];
            int nCol = c+delCol[i];
            
            if(nRow>=0 && nRow<row && nCol>=0 && nCol<col && grid[nRow][nCol] == 1){
                
                dfsSol(grid,nRow,nCol);
                
            }
            
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& gr) {
        
        //making a duplicate because I don't want to change the actual data.
        //we can also make a visited array and then solve
        vector<vector<int>> grid = gr;
        
        int row = grid.size();
        int col = grid[0].size();
        
        // vector<vector<int>> visited(row,vector<int>(col,0));
        
        //can be solved using BFS or DFS
        
        //take care of top and bottom boundary
        for(int i = 0;i<col;i++){
            
            //top
            if(grid[0][i] == 1)
                dfsSol(grid,0,i);
            
            //bottom
            if(grid[row-1][i] == 1)
                dfsSol(grid,row-1,i);
            
            
        }
        
        //take care of left and right boundary
        for(int i = 0;i<row;i++){
            
            //left
            if(grid[i][0] == 1)
                dfsSol(grid,i,0);
            
            //right
            if(grid[i][col-1] == 1)
                dfsSol(grid,i,col-1);
            
        }
        
        //count the number of landcells which is not visited
        
        int count = 0;
        
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(grid[i][j] == 1)
                    count++;
                
            }
            
        }
        
        return count;
        
    }
};