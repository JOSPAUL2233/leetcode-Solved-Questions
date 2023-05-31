//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        int minFreq = INT_MAX;
        int ans = INT_MIN;
        
        map<int,int> freq;
        
        for(int i = 0;i<n;i++){
            
            freq[arr[i]]++;
            
        }
        
        
        for(auto i : freq){
            
            if(i.second < minFreq){
                
                minFreq = i.second;
                
            }
            
        }
        
        for(auto i : freq){
            
            if(i.second == minFreq && i.first > ans) ans = i.first;
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends