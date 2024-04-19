class Solution {
public:
    
    bool isValid(int r,int c,int row,int col){
        
        return (r>=0 && r<row && c>=0 && c<col);
        
    }
    void bfs(vector<vector<char>> grid,int r,int c,vector<vector<int>> &visited){
        
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> que;
        que.push({r,c});
        
        //maintain a delta row and col array for storing the increment
        //values for four neighbours
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};   
        
        while(!que.empty()){
            
            pair<int,int> node = que.front();
            que.pop();
            
            int i = node.first;
            int j = node.second;
            
            //go for all the 4-neibours
            for(int k = 0;k<4;k++){
                
                //update to new direction nodes
                int rNode = delRow[k] + i;
                int cNode = delCol[k] + j;
                
                if(isValid(rNode,cNode,row,col) && grid[rNode][cNode] == '1' && !visited[rNode][cNode]){
                    
                    visited[rNode][cNode] = 1;
                    que.push({rNode,cNode});
                    
                }
                
                
            }
                        
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
                
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> visited(row,vector<int>(col,0));
        
        int count = 0;
        
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(grid[i][j] == '1' && !visited[i][j]){
                    
                    visited[i][j] = 1;
                    bfs(grid,i,j,visited);//we can also go for dfs
                    count++;//keep track of number of traversals, which is the answer
                    
                }
                
            }
            
        }
        
        return count;
        
    }
};