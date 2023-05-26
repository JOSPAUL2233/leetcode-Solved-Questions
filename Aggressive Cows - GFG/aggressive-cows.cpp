//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    
    bool isPossible(vector<int> stalls,int n,int k,int mid){
        
        
        int cowLocation = stalls[0];
        int cowCount = 1;
        
        for(int i = 1;i<n;i++){
            
            int dif = stalls[i] - cowLocation;
            
            if(dif >= mid){
                
                cowCount++;
                
                if(cowCount == k)return true;
                
                cowLocation = stalls[i];
                
            }
            
        }
        
        return false;
        
    }
    
public:
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());//sort the given array
    
        int start = 1;
        int end = stalls[n-1] - stalls[0];
        int ans = -1;
        
        //binary search
        while(start<=end){

            int mid = start+(end-start)/2;
            
            if(isPossible(stalls,n,k,mid)){
                
                //we have to find the maximum value
                ans = mid;
                start = mid+1;
                
            }else{
                
                //reduce the distance
                end = mid-1;
                
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends