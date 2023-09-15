class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int maxElement = n*n;
        int count = 1;
        
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        while(count <= maxElement){
            
            //TOP PART
            for(int i = left;i<=right && count <= maxElement;i++){
                
                ans[top][i] = count++;
                                
            }
            
            top++;
            
            //RIGHT PART
            for(int i = top;i<=bottom && count <= maxElement;i++){
                
                ans[i][right] = count++;
                                
            }
            right--;
            
            //BOTTOM PART
            for(int i = right;i>=left && count <= maxElement;i--){
                
                ans[bottom][i] = count++;
                
            }
            bottom--;
            
            //LEFT PART
            for(int i = bottom;i>=top && count <= maxElement;i--){
                
                ans[i][left] = count++;
                
            }
            left++;
            
        }
        
        return ans;
        
    }
};