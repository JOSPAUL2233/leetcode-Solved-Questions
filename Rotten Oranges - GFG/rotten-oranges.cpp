//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
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
                
                //left -->i,j-1
                if(j-1 >= 0 && grid[i][j-1] == 1 && !visited[i][j-1]){
                    
                    visited[i][j-1] = 1;
                    que.push({i,j-1});
                    
                }
                
                //right --> i,j+1
                if(j+1 < col && grid[i][j+1] == 1 && !visited[i][j+1]){
                    
                    visited[i][j+1] = 1;
                    que.push({i,j+1});
                    
                }         
                
                //up --> i-1,j
                if(i-1 >= 0 && grid[i-1][j] == 1 && !visited[i-1][j]){
                    
                    visited[i-1][j] = 1;
                    que.push({i-1,j});
                    
                }       
                
                //down --> i+1,j
                if(i+1 < row && grid[i+1][j] == 1 && !visited[i+1][j]){
                    
                    visited[i+1][j] = 1;
                    que.push({i+1,j});

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