//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPossible(int arr[],int n,int d,int limit){
        
        int totalWeight = 0;
        int totalDays = 1;
        
        for(int i = 0;i<n;i++){
            
            if(totalWeight + arr[i] <= limit){
                
                totalWeight += arr[i];
                
            }else{
                
                totalWeight = arr[i];
                totalDays++;
                
                if(totalDays > d)
                    return false;
                
            }
            
        }
        
        return true;
        
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        
        //the range is from maxElement till sumof all the weights
        
        int start = INT_MIN;
        int end = 0;
        
        for(int i = 0;i<N;i++){
            
            start = max(start,arr[i]);
            end += arr[i];
            
        }
        
        int ans = -1;
        
        //apply binary search
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(arr,N,D,mid)){
                
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends