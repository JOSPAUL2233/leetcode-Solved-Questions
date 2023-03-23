class Solution {

    bool isSafe(int i , int j, vector<vector<int>> grid,vector<vector<int>> visited,int m,int n){
                
        if(i<m && i>=0 && j<n && j>=0 && grid[i][j]!=-1 && visited[i][j] != 1){
            return true;
        }else
            return false;
        
    }
    
    
    bool isVisited(vector<vector<int>> &visited,vector<vector<int>> &grid){
        
        for(int i = 0;i<visited.size();i++){
            
            for(int j = 0;j<visited[0].size();j++){
                
                if(visited[i][j] == 0 && grid[i][j] != -1)return false;
                
            }
            
        }
        
        return true;
        
    }
    
    void solve(vector<vector<int>> &grid,vector<vector<int>>& visited,
               int &ans,int i,int j,int m,int n){
        
        // cout<<"i:"<<i<<endl<<"j:"<<j<<endl<<endl;
        
        // reached the ending index
        if(grid[i][j]==2){
            
            // cout<<"hello"<<endl;
            
            visited[i][j] = 1;
            //check if all the indices are visited or not
            
            if(isVisited(visited,grid)){
                ans++;
            }
            
            visited[i][j] = 0;
            return;
        }
        
        
        //LEFT(i,j-1)
       
        if(isSafe(i,j-1,grid,visited,m,n)){
            
            visited[i][j-1] = 1;
            solve(grid,visited,ans,i,j-1,m,n);
            visited[i][j-1] = 0;
            
        }
        
        //RIGHT(i,j+1)
        
        if(isSafe(i,j+1,grid,visited,m,n)){
            // cout<<"i:"<<i<<endl<<"j:"<<j<<endl;
            visited[i][j+1] = 1;
            solve(grid,visited,ans,i,j+1,m,n);
            visited[i][j+1] = 0;
            
        }
        
        //UP(i-1,j)
        
        if(isSafe(i-1,j,grid,visited,m,n)){
            
            visited[i-1][j] = 1;
            solve(grid,visited,ans,i-1,j,m,n);
            visited[i-1][j] = 0;
            
        }
        
        //DOWN(i+1,j)
        
        if(isSafe(i+1,j,grid,visited,m,n)){
            
            visited[i+1][j] = 1;
            solve(grid,visited,ans,i+1,j,m,n);
            visited[i+1][j] = 0;
            
        }
         
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int i = 0;
        int j = 0;
        
        int ans = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        
        //FIND THE STARTING POSITION
        
        for(int k = 0;k<m;k++){
            
            for(int l = 0;l<n;l++){
                
                if(grid[k][l] == 1){
                    i = k;
                    j = l;
                }
                
            }
            
        }        
        
        
        visited[i][j] = 1;
        
        solve(grid,visited,ans,i,j,m,n);
        
        return ans;
        
        
    }
};