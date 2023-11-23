//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        sort(A,A+n);
        sort(B,B+m);
        
        int sumA = 0;
        int sumB = 0;
        
        for(int i = 0;i<n;i++)
            sumA += A[i];
            
        for(int i = 0;i<m;i++)
            sumB += B[i];
        
        while(ptr1 < n && ptr2 < m){
            
            int diff = A[ptr1] - B[ptr2];
            
            sumB += diff;
            sumA -= diff;
            
            if(sumA == sumB){
                return 1;
            }else if(sumA < sumB){
                
                sumB -= diff;
                sumA += diff;
                
                ptr2++;
                
            }else{
                
                sumB -= diff;
                sumA += diff;
                
                ptr1++;                
            }

        }
        
        return -1;
        
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends