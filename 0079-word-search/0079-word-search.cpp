class Solution {
public:
    
    bool check(vector<vector<char>> &board,string word, int index,int row,int col){
        
        int rowMax = board.size();
        int colMax = board[0].size();

        //base cases
        if(board[row][col] != word[index])
            return false;
        
        
        if(index == word.size() - 1){
            return true;
        }
        
        //mark as visited
        char temp = board[row][col];
        board[row][col] = '*';
        index++;
        
        //decide the direction--
        
        
        //top
        if(col-1 >= 0 && board[row][col-1] != '*')
            if(check(board,word,index,row,col-1))
                return true;
        
        //right
        if(row + 1 < rowMax && board[row+1][col] != '*')
            if(check(board,word,index,row+1,col))
                return true;
        
        //bottom
        if(col + 1 < colMax && board[row][col+1] != '*')
            if(check(board,word,index,row,col+1))
                return true;
        
        //left
        if(row - 1 >= 0 && board[row-1][col] != '*')
            if(check(board,word,index,row-1,col))
                return true;

        
        board[row][col] = temp;
        index--;
                
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int rowMax = board.size();
        int colMax = board[0].size();
                
        char start = word[0];
                
        //check for the first char
        for(int i = 0;i<rowMax;i++){
            
            for(int j = 0;j<colMax;j++){
                
                if(board[i][j] == start){
                    
                    if(check(board,word,0,i,j))
                        return true;
                    
                }
                
            }
            
        }
        
        return false;
                
    }
};