//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        int top = 0;
        int bottom = r-1;
        int left = 0;
        int right = c-1;
        
        int count = 0;
        int maxCount = r*c;
        
        vector<int> ans;
        
        while(count < maxCount){
            
            
            //print the top row
            for(int i = left;i<=right && count < maxCount;i++){
                
                ans.push_back(matrix[top][i]);
                count++;
                
            }
            
            top++;
            
            //print the right column
            for(int i = top;i<=bottom && count < maxCount;i++){
                
                ans.push_back(matrix[i][right]);
                count++;
                
            }
            
            right--;
            
            //print the bottom row
            for(int i = right;i>=left && count < maxCount;i--){
                
                ans.push_back(matrix[bottom][i]);
                count++;
                
            }
            
            bottom--;
            
            //print the left col
            for(int i = bottom;i>=top && count < maxCount;i--){
                
                ans.push_back(matrix[i][left]);
                count++;
                
            }
            left++;
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends