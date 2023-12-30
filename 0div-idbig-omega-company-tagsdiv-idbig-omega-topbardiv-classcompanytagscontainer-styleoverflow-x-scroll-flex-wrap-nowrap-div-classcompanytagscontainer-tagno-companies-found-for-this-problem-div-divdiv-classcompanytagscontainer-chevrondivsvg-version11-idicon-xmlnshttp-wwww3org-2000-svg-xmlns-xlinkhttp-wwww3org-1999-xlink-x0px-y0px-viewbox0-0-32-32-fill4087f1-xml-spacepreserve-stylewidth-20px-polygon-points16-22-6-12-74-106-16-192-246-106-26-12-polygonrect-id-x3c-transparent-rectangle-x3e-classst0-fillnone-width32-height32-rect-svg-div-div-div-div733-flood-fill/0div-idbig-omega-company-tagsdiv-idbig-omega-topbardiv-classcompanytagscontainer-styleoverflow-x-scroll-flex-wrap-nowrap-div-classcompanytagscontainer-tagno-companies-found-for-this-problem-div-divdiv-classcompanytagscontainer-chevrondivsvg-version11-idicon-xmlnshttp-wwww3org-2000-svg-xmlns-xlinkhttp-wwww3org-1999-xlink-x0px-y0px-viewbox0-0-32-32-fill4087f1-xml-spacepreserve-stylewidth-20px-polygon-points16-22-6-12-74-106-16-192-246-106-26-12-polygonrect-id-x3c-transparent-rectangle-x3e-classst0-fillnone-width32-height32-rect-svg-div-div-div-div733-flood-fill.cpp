class Solution {
public:
    
    bool isValid(int r,int c,int row,int col){
        
        return (r>=0 && r<row && c>=0 && c<col);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        //staight away do bfs/dfs traversal with the given conditions
        
        int row = image.size();
        int col = image[0].size();
        
        //store the initial color and change the color to new specified color
        int iniColor = image[sr][sc];
        image[sr][sc] = color;
        
        //take care of edge case
        if(iniColor == color)
            return image;
        
        //keep a track of neighbour increment values
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        queue<pair<int,int>> que;
        que.push({sr,sc});
        
        while(!que.empty()){
            
            int i = que.front().first;
            int j = que.front().second;
            
            que.pop();
            
            for(int k = 0;k<4;k++){
                
                int nr = i + delRow[k];
                int nc = j + delCol[k];
                
                if(isValid(nr,nc,row,col) && image[nr][nc] == iniColor){
                    
                    image[nr][nc] = color;
                    que.push({nr,nc});
                    
                }
                
            }
            
        }
        
        return image;
        
    }
};