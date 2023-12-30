//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    bool isValid(int r,int c,int row,int col){
        
        return (r>=0 && r<row && c>=0 && c<col);
        
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> que; //{{x,y},level}
        vector<vector<int>> visited(row,vector<int>(col,0));
        
        //push all the rotten indices into the queue
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(grid[i][j] == 2){
                    
                    visited[i][j] = 1;
                    que.push({i,j});
                    
                }
                
            }
            
        }
        
        //make a deltaRow and deltaCol for the four neibours indices
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        int time = 0;
        
        while(!que.empty()){
            
            //take out the size of the queue and process with all the elements inside the queue
            int size = que.size();
            
            for(int it = 0;it<size;it++){
                
                //take out the front node indices
                
                pair<int,int> indices = que.front();
                que.pop();
                
                int i = indices.first;
                int j = indices.second;
                
                //push all the fresh oranges which are neibours(make neibours rotten)
                
                for(int k = 0;k<4;k++){
                    
                    //change indices according to the neibouring directions
                    int r = i + delRow[k];
                    int c = j + delCol[k];
                    
                    //make it rotten if valid
                    if(isValid(r,c,row,col) && grid[r][c] == 1 && !visited[r][c]){
                        
                        visited[r][c] = 1;
                        que.push({r,c});
    
                    }
                
                }
            }
            
            //increment the time
            if(!que.empty())
                time++;
            
        }
        
        //check if there are some oranges fresh still even after rotting all the possible
        //oranges, if yes return -1
        
        for(int i = 0;i<row;i++){
            
            for(int j = 0;j<col;j++){
                
                if(grid[i][j] == 1 && visited[i][j] != 1)
                    return -1;
                
            }
            
        }
        
        return time;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends