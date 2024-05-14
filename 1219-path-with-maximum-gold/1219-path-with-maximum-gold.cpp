class Solution {
public:

    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,+1,0,-1};

    int getMaxSum(vector<vector<int>>& grid,int r,int c){

        int row = grid.size();
        int col = grid[0].size();

        //as I enter this area, I'm taking all the golds
        int currGold = grid[r][c];
        grid[r][c] = 0;

        int sum = 0;

        //traversing through all the four sides
        for(int i = 0;i<4;i++){

            int nr = r+delRow[i];//new row
            int nc = c+delCol[i];//new col
            
            //only traverse to that column which is not 0 and not visited till now
            if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] != 0)
                sum = max(sum,getMaxSum(grid,nr,nc));

        }

        //as I'm leaving this area, I'm placing the gold which I took
        grid[r][c] = currGold;

        return currGold + sum;


    }

    int getMaximumGold(vector<vector<int>>& grid) {

        int maxi = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){

                if(grid[i][j] != 0){
                    int sum = getMaxSum(grid,i,j);
                    maxi = max(maxi,sum);
                }

            }
        }

        return maxi;
        
    }
};