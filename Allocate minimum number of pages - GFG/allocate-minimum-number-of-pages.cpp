//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    
    
    bool isPossible(int A[],int N,int M,int mid){
        
        int stdCount = 1;
        int page = 0;
        
        for(int i = 0;i<N;i++){
            
            if(A[i]>mid)return false;
            
            if(page + A[i] > mid){
                
                stdCount++;
                
                if(stdCount>M)return false;
                
                page = A[i];
                
            }else{
                
                page+=A[i];
                
            }
            
        }
        
        
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M)return -1;
        
        int start = 0;
        int end = 0;
        int ans = -1;
        
        //assign start and end
        
        for(int i = 0;i<N;i++){
            
            if(A[i]<start)start = A[i];
            
            end+=A[i];
            
        }
        
        //binary search
        
        while(start<=end){
            
            int mid = start+(end-start)/2;
            
            if(isPossible(A,N,M,mid)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends