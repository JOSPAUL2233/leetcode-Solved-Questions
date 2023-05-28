//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int ele = a[0];
        int count = 0;
        
        for(int i = 0;i<size;i++){
            
            if(a[i]==ele)
                count++;
            else
                count--;
                
            if(count==0){
                ele = a[i];
                count = 1;
            }
            
        }
        
        //a possible answer is ele if majority element
        //exists.
        //So,check if the ele exists or not by checking
        //it's count
        
        int counter = 0;
        
        for(int i = 0;i<size;i++){
            
            if(a[i]==ele)counter++;
            
        }
        
        if(counter > (size/2))
            return ele;//if exists
        else
            return -1;//if not exists

    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends