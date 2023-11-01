//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        int leftMax = 0;
        int rightMax = 0;
        
        int left = 0;
        int right = n-1;
        
        long long totalWater = 0;
        
        while(left < right){
            
            //take the side which has a support of the opposite side
            if(arr[left] <= arr[right]){
                
                //if there is water
                if(arr[left] < leftMax){
                    long long water = leftMax - arr[left];
                    totalWater += water;
                }else{
                    leftMax = arr[left];
                }
                
                left++;
                
                
            }else{
                
                //if there is water
                if(arr[right] < rightMax){
                    long long water = rightMax - arr[right];
                    totalWater += water;
                }else{
                    
                    rightMax = arr[right];
                    
                }
                
                right--;
                
            }
            
        }
        
        return totalWater;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends