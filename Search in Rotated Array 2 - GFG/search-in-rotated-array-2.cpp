//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        
        int start = 0;
        int end = N-1;
        
        while(start<=end){
            
            int mid = start+(end - start)/2;
            
            if(A[mid] == Key)
                return true;
            
            //we have handle this case
            if(A[start] == A[mid] && A[mid] == A[end]){
                
                start++;
                end--;
                continue;
                
            }
            
            //choose the sorted part
            
            if(A[mid] >= A[start]){//left part
                
                if(Key >= A[start] && Key < A[mid]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
                
            }else{//right part
                
                if(Key > A[mid] && Key <= A[end])
                    start = mid+1;
                else
                    end = mid-1;
                
            }
            
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends