class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> que;
        
        int maxRow = matrix.size();
        int maxCol = matrix[0].size();
        
        for(int i = 0;i<maxRow;i++){
            
            for(int j = 0;j<maxCol;j++){
                
                que.push(matrix[i][j]);
                
                //remove the element if it exceeds k
                if(que.size() > k)
                    que.pop();
                
            }
            
        }
        
        return que.top();
        
    }
};