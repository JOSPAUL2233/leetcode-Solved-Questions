class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0;i<row;i++){
            
            vector<int> vec;
            
            for(int j = 0;j<col;j++){
                                
                if(i-1 >= 0 && i+1 < row && j-1 >=0 && j+1<col){

                    int maxi = grid[i][j];
                    for(int k = -1;k<=+1;k++){
                        for(int l = -1;l<=+1;l++){
                            maxi = max(maxi,grid[i+k][j+l]);
                        }
                    }
                    
                    vec.push_back(maxi);
                    
                }
                                
            }
            if(vec.size())
                ans.push_back(vec);
        }
        
        return ans;
        
    }
};