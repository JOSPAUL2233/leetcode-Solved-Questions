//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //sizes
        int totalSize = n + m;
        
        //initialize the pointers
        int ptr1 = 0;
        int ptr2 = 0;
        int count = 1;
        
        //keep a track of count which acts as the index of new formed virtual array
        while(ptr1 < n && ptr2 < m){
            
            if(arr1[ptr1] < arr2[ptr2]){
                
                //checking for the index
                if(count == k)
                    return arr1[ptr1];
                    
                ptr1++;

            }else{
                
                //checking for the index
                if(count == k)
                    return arr2[ptr2];
                    
                ptr2++;                
            }
            
            count++;

        }
        
        //if there are elements left to check in any of the array
        while(ptr1 < n){
            
                //checking for the index
                if(count == k)
                    return arr1[ptr1];
                    
                ptr1++;
                count++;
        }
        while(ptr2 < m){
            
                //checking for the index
                if(count == k)
                    return arr2[ptr2];
                    
                ptr2++;  
                count++;
        }
        
        //if the position is not found
        return -1;
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends