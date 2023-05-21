class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        int s = 0;
        int e = 0;
        
        int numS = score.size();
        int numE = score[0].size();
        
        for(int i = 0;i<numS-1;i++){
            
            int maxIndex = i;
            
            for(int j = i+1;j<numS;j++){
                    
                    if(score[j][k] > score[maxIndex][k])maxIndex = j;
                    
                }
            
            //swap the elem
            if(maxIndex != i){
                
                for(int j = 0;j<numE;j++){
                    
                    int temp = score[maxIndex][j];
                    score[maxIndex][j] = score[i][j];
                    score[i][j] = temp;   
                    
                }
                
            }
            
        }
        
        return score;
        
    }
};