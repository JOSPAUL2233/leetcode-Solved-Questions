//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool isPossible(int arr[],int n,int k,int mid){
      
      int splits = 1;
      int currSum = 0;
      
      for(int i = 0;i<n;i++){
          
          //edge case
          if(arr[i] > mid)
            return false;
            
            int sum = currSum + arr[i];
            
            if(sum > mid){
                
                splits++;
                currSum = arr[i];
                
                if(splits > k)
                    return false;
                
            }else{
                
                currSum += arr[i];
                
            }
          
      }

      return true;
      
  }
    int splitArray(int arr[] ,int N, int K) {
        
        int start = INT_MIN;
        int end = 0;
        
        for(int i = 0;i<N;i++){
            
            start = max(start,arr[i]);
            end += arr[i];
            
        }
        
        int ans = -1;
        //go for binary search
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(arr,N,K,mid)){
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
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends