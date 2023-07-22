//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        
        //we will store prefixSum
        map<int,int> prefixSum;
        
        int sum = 0;
        int maxLength = INT_MIN;

        for(int i = 0;i<n;i++){
            
            sum += A[i];
            
            //find the element removing which we get 0
            int rem = sum;
            
            if(sum == 0){
                maxLength = i+1;
            }

            //check if that element is found already
            if(prefixSum.find(rem) != prefixSum.end()){
                
                maxLength = max(maxLength , (i - prefixSum[rem]));
                
            }
            
            //store only if the sum is not present anywhere left side
            //since we have to find the maximum length
            if(prefixSum.find(sum) == prefixSum.end())
                prefixSum[sum] = i;
                
        }
        
        if(maxLength == INT_MIN)
            return 0;
        else
            return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends