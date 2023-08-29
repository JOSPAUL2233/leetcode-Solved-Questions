class Solution {
public:
    
    bool isValid(vector<vector<char>>& board,char ch,int row,int col){
        
        //run a loop from 0 to 8
        
        for(int i = 0 ; i < 9 ; i++){
            
            //check for row
            if(board[row][i] == ch)
                return false;
            
            //check for col
            if(board[i][col] == ch)
                return false;
            
            //check inside grids(watch striver video to understand the intuition)
            if(board[3 * (row/3) + (i / 3)][3 * (col/3) + (i % 3)] == ch)
                return false;
            
        }
        
        //it is a valid to put element in this column
        return true;
        
    }
    
//     bool solve(vector < vector < char >> & board) {
        
//       for (int i = 0; i < board.size(); i++) {
          
//         for (int j = 0; j < board[0].size(); j++) {
            
//           if (board[i][j] == '.') {
              
//             for (char c = '1'; c <= '9'; c++) {
                
//               if (isValid(board, c, i, j)) {
                  
//                 board[i][j] = c;

//                 if (solve(board))
//                   return true;

//                   board[i][j] = '.';
//               }
//             }

//             return false;
//           }
//         }
//       }
//   return true;
// }
    
    bool solve(vector<vector<char>>& board) {
        
        //iterate through all the columns
        for(int i = 0;i<board.size();i++){
            
            for(int j = 0;j<board[0].size();j++){
                
                // cout<<"item: " <<board[i][j]<<endl;
                
                //find the empty box
                if(board[i][j] == '.'){
                    
                    //try putting all the elements from 1 till 9
                    for(char ch = '1';ch <= '9'; ch++){
                        //check if ch can be put into the current box
                        if(isValid(board,ch,i,j)){
                                cout<<ch<<endl;

                            
                            //place the element
                            board[i][j] = ch;
                            
                            if(solve(board))
                                return true;

                            //remove the element which was placed (Backtrack)
                            board[i][j] = '.';
                            
                            
                        }
                                                    
                    }
                    
                    //after putting all the possiblitites in the empty space,
                    //it coudn't solve the soduku
                    return false;
                    
                }
                
            }
            
        }
        
        //if it couldn't find any index empty which means sodoku is solved.
        return true;
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
    
        //call the recursive function
        solve(board);
    
    }
};