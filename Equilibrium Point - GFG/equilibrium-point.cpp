//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<vector>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        
        if(n == 1)
            return a[0];
    
        //maintain a prefix sum and postfix sum
        
        vector<int> prefix(n,0);
        vector<int> postfix(n,0);
        
        int preSum = 0;
        int postSum = 0;
        
        for(int i = 0;i<n;i++){
            
            preSum += a[i];
            postSum += a[n-1-i];
            
            prefix[i] = preSum;
            postfix[n-1-i] = postSum;
            
        }

        //now, check for the condition for each index
        
        for(int i = 0;i<n;i++){
            
            if(i == 0){
                
                if(postfix[i+1] == 0)
                    return i+1;
                
            }
            
            if(i == n-1){
                
                if(prefix[i-1] == 0)
                    return i+1;
                
            }
            
            if(prefix[i-1] == postfix[i+1])
                return i+1;
            
        }
        
        return -1;
        
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends