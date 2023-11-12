//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        
        int start = low;
        int end = high;
        
        int mini = INT_MAX;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            //choose the sorted part
            
            if(arr[start] <= arr[mid]){//LEFT PART IS SORTED
                
                //take out the mini in tis part and search in other part
                mini = min(mini,arr[start]);
                start = mid+1;
                
            }else{//RIGHT PART IS SORTED
                
                //take out the mini in tis part and search in other part
                mini = min(mini,arr[mid]);
                end = mid-1;
                
            }
            
        }
        
        return mini;
        
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends