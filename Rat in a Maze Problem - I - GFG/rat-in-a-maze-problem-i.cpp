//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    void solve(vector<vector<int>> arr, vector<vector<int>> visited,
            string path, vector<string> &ans,int i,int j,int n){
                
                //base case
                if(i == n-1 && j == n-1){
                    
                    ans.push_back(path);
                    return;
                    
                }
                
                //mark this point as visited
                visited[i][j] = 1;
                
                //check for moving UP
                int newI = i-1;
                int newJ = j;
                
                if(newI >= 0 && visited[newI][newJ] == 0 && arr[newI][newJ] != 0){
                    
                    path.push_back('U');
                    solve(arr,visited,path,ans,newI,newJ,n);
                    path.pop_back();
                    
                }
                
                //check for moving RIGHT
                newI = i;
                newJ = j+1;
                
                if(newJ < n && visited[newI][newJ] == 0 && arr[newI][newJ] != 0){
                    
                    path.push_back('R');
                    solve(arr,visited,path,ans,newI,newJ,n);
                    path.pop_back();
                    
                }
                
                //check for moving DOWN
                newI = i+1;
                newJ = j;
                
                if(newI < n && visited[newI][newJ] == 0 && arr[newI][newJ] != 0){
                    
                    path.push_back('D');
                    solve(arr,visited,path,ans,newI,newJ,n);
                    path.pop_back();
                    
                }
                
                //check for moving LEFT
                newI = i;
                newJ = j-1;
                
                if(newJ >= 0 && visited[newI][newJ] == 0 && arr[newI][newJ] != 0){
                    
                    path.push_back('L');
                    solve(arr,visited,path,ans,newI,newJ,n);
                    path.pop_back();
                    
                }
                
                //remove the visited mark
                //we are leaving this point
                visited[i][j] = 0;
                
            }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        //visited array to keep track of visited path
        vector<vector<int>> visited(n,vector<int> (n,0));
        
        //initial position
        int i = 0;
        int j = 0;
        
        //if the initial position is not allowd
        if(m[i][j] == 0)
            return {};
        
        //current path
        string path = "";
        
        //all possible paths (final answer)
        vector<string> ans;
        
        //recursive function to solve the problem
        solve(m,visited,path,ans,i,j,n);
        
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