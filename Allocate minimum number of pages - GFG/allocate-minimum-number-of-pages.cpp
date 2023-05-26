//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    
    bool isPossible(int mid,int A[],int N,int M){
        
        int stdCount = 1;
        int pages = 0;
        
        for(int i = 0;i<N;i++){
            
            if(A[i]>mid)return false; //if the element is greater than the limit
            
            if(A[i]+pages > mid){
                
                //increase the student and start allocating pages from there
                stdCount++;
                
                if(stdCount>M)return false;// if the students exceeds
                
                pages = A[i];
                
            }else{
                
                pages+=A[i]; //keep on increasing page for same studdent
                
            }
            
        }
        
        return true;
        
    }

    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M)return -1;
        
        //start = min element
        //end = sum of all the elements
        
        int start = 0;
        int end = 0;
        int ans = -1;
        
        for(int i = 0;i<N;i++){
            
            if(start>A[i])start = A[i];
            
            end+=A[i];
            
        }
        
        //binary search
        
        while(start<=end){
            
            int mid = start+(end-start)/2;
            
            if(isPossible(mid,A,N,M)){
                
                //store the answer and look for min value
                ans = mid;
                end = mid-1;

            }else{
                //increase the limit
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