class Solution {
public:
    
    int mod = 1000000007;
    
    int solve(int r,int c,int maxi,int row,int col,vector<vector<vector<int>>> &dp){
        
        //came out
        if(r >= row || r<0 || c >= col || c<0)
            return 1;
        
        //reached max and didn't go out
        if(maxi == 0)
            return 0;
                
        //move four sides
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        if(dp[r][c][maxi] != -1)
            return dp[r][c][maxi];
        
        int ans = 0;
        
        for(int i = 0;i<4;i++){
            
            int nr = r+delRow[i];
            int nc = c+delCol[i];
            
            ans = (ans + solve(nr,nc,maxi-1,row,col,dp))% mod;
            
        }
        
        return dp[r][c][maxi] = ans;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        //m rows, n cols
        
        //maintain dp [row][coo][moves]
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, (vector<int>(maxMove+1,-1))));
        
        return solve(startRow,startColumn,maxMove,m,n,dp);
        
    }
};