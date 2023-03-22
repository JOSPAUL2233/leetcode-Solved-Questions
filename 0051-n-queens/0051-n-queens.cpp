class Solution {
    
    void storeAns(vector<vector<char>> board,vector<vector<string>> &ans,int n){
        
        //store whatever is there in the board in to the ans
        vector<string> temp;
            
            for(int i = 0;i<n;i++){
                
                string s = "";
                
                for(int j = 0;j<n;j++){
                    
                        if(board[i][j]=='Q')s+='Q';
                        else s+='.';
                    
                }
                
                temp.push_back(s);
                
            }
            
            ans.push_back(temp);
        
    }
    
    bool isSafe(vector<vector<char>> &board,int n,int col,int raw){
        
        //check for left-top diagonal
        
        int x = col;
        int y = raw;
        
        while(x>=0 && y>=0){
            
            if(board[y][x]=='Q')return false;
            
            x--;
            y--;
        }
        
        //check for left-bottom diagonal
        x = col;
        y = raw;
        while(x>=0 && y<n){
            
            if(board[y][x]=='Q')return false;
            
            x--;
            y++;
        }
        
        //check for left side
        x = col;
        y = raw;
        while(x>=0){
            
            if(board[y][x]=='Q')return false;
            
            x--;
        }
        
        return true;
        
    }
    
    void solve(vector<vector<char>> &board,int n,int col,vector<vector<string>> &ans){
        
        
        //BASE CASE -- INCASE COL EXCCEEDS THE BOARD
        if(col==n){
            
            storeAns(board,ans,n);
            return;
            
        }
        
        //looping through all the raws in the same col
        
        for(int raw = 0;raw < n;raw++){
            
            
            if(isSafe(board,n,col,raw)){
                
            board[raw][col] = 'Q';
            solve(board,n,col+1,ans);
            board[raw][col] = '.';
                
            }
            
            
        }
           
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        // MAKE CHESS BOARD
        vector<vector<char>> board(n,vector<char>(n,'.'));
        
        int col = 0;
        
        vector<vector<string>> ans;
        
        solve(board,n,col,ans);
        
        return ans;
        
        
    }
};