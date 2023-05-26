//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int> hashArr(n+1,0);
       
       int repeat = -1;
       int missing = -1;
       
       for(int i = 0;i<n;i++){
           
           hashArr[arr[i]]++;
           
       }
       for(int i = 0;i<hashArr.size();i++){
           
           if(hashArr[i]==2)repeat = i;
           if(hashArr[i]==0 && i!=0)missing = i;
           
       }
       
       return {repeat,missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends