class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     
        vector<set<int>> r(9) , c(9) , b(9);
        
        for(int i = 0;i<9;i++){
            
            for(int j = 0;j<9;j++){
                
                
                if(board[i][j]=='.')continue;
                
                int num = board[i][j]-'0';
                
                if(r[i].count(num) || c[j].count(num) || b[(i/3)*3+j/3].count(num))return false;
                
                r[i].insert(num);
                c[j].insert(num);
                b[(i/3)*3+j/3].insert(num);
                
                
            }            
            
        }
        return true;
    }
};