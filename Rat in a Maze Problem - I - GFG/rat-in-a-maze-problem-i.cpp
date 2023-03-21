//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    void solve(vector<vector<int>> arr,int i,int j,
        string curr,vector<string> &ans,vector<vector<int>> visited,int n){
        
        //DESTINATION
        
        if(i==n-1 && j==n-1){
            ans.push_back(curr);
            return;
        }

        //LEFT (i,j-1)
        
        if(j-1>=0 && visited[i][j-1]==0 && arr[i][j-1]==1){
            
            curr+='L';
            visited[i][j-1]=1;
            
            solve(arr,i,j-1,curr,ans,visited,n);
            
            visited[i][j-1]=0;
            curr.pop_back();
            
        }
        
        //RIGHT(i,j+1)
        
        if(j+1<=n-1 && visited[i][j+1]==0 && arr[i][j+1]==1){
            
            curr+='R';
            visited[i][j+1]=1;
            
            solve(arr,i,j+1,curr,ans,visited,n);
            
            visited[i][j+1]=0;
            curr.pop_back();
            
        }
        
        //UP(i-1,j)
        
        if(i-1>=0 && visited[i-1][j]==0 && arr[i-1][j]==1){
            
            curr+='U';
            visited[i-1][j]=1;
            
            solve(arr,i-1,j,curr,ans,visited,n);
            
            visited[i-1][j]=0;
            curr.pop_back();
            
        }
        
        //DOWN(i+1,j)
        
        if(i+1<=n-1 && visited[i+1][j]==0 && arr[i+1][j]==1){
            
            curr+='D';
            visited[i+1][j] = 1;
            
            solve(arr,i+1,j,curr,ans,visited,n);
            
            visited[i+1][j] = 0;
            curr.pop_back();
            
        }
        
        
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {

    vector<string> ans;
    
    vector<vector<int>> visited(n,vector<int>(n,0));
    
    string curr = "";
    
    int i = 0;
    int j = 0;
    
    if(m[i][j]==0)return{};
    
    visited[i][j] = 1;
    
    solve(m,i,j,curr,ans,visited,n);
    
    return ans;


    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends