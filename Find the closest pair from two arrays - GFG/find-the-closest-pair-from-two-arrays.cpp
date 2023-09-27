//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        
        int ptr1 = 0;
        int ptr2 = m-1;
        
        vector<int> ans(2,-1);
        int minDiff = INT_MAX;
        
        while(ptr1 < n && ptr2 >= 0){
            
            int sum = arr[ptr1] + brr[ptr2];
            
            int diff = abs(x-sum);
            
            if(diff == 0){
                
                ans[0] = arr[ptr1];
                ans[1] = brr[ptr2];
                break;
                
            }else{
                
                if(diff < minDiff){
                    
                    ans[0] = arr[ptr1];
                    ans[1] = brr[ptr2];
                    
                    minDiff = diff;
                }
                
                if(sum < x)
                    ptr1++;
                else
                    ptr2--;
                
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends