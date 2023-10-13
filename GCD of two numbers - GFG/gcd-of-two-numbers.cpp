//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
	
	int findGCD(int a,int b){
	    
	    if(b == 0)
	        return a;
	        
	    return findGCD(b,a%b);
	    
	}
	
	
    int gcd(int A, int B) 
	{ 
	    
	    int ans = -1;
	    if(A>B)
	        ans = findGCD(A,B);
	    else
	       ans = findGCD(B,A);
	       
	   return ans;
	      
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends