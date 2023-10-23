//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void reverse(vector<int> &vec,int left,int right){
        
        
        while(left < right){
            
            swap(vec[left],vec[right]);
            
            left++;
            right--;
        }
        
    }

    vector<int> nextPermutation(int N, vector<int> arr){
        
        //step 1 -> find the breaking point
        int breaking = -1;
        
        for(int i = N-2;i>=0;i--){
            
            if(arr[i] < arr[i+1]){
                
                breaking = i;
                break;
                
            }
            
        }
        
        //if there is no breaking point
        if(breaking == -1){
            
            reverse(arr,0,N-1);
            return arr;
            
        }
        
        
        //if there is a breaking point, then follow algorithm
        
        //find the just greater element after breaking point
        int greater = -1;
        
        for(int i = N-1;i>breaking;i--){
            
            if(arr[i] > arr[breaking]){
                
                greater = i;
                break;
                
            }
            
        }
        
        swap(arr[breaking],arr[greater]);
        
        //sort the right part
        //so for that, let's reverse it
        reverse(arr,breaking+1,N-1);
        
        return arr;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends