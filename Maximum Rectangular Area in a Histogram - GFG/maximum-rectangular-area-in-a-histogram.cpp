//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long> prevSmallerElement(long long arr[],int n){
        
        stack<long long> st;
        vector<long long> ans(n,0);
        
        for(int i = 0;i<n;i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
                
            st.push(i);

        }
        
        return ans;
        
    }
    
    vector<long long> nextSmallerElement(long long arr[],int n){
        
        stack<long long> st;
        vector<long long> ans(n,0);
        
        for(int i = n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
                
            st.push(i);

        }
        
        return ans;        
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        
        vector<long long> prevSmaller = prevSmallerElement(arr,n);
        vector<long long> nextSmaller = nextSmallerElement(arr,n);
        
        long long maxArea = INT_MIN;
        
        for(int i = 0;i<n;i++){
            
            if(nextSmaller[i] == -1)
                nextSmaller[i] = n;
            
            long long width = nextSmaller[i] - prevSmaller[i] - 1;
            long long height = arr[i];
            
            // cout<<"i:"<<arr[i]<<endl;
            // cout<<nextSmaller[i]<<endl;
            // cout<<width<<" "<<height<<endl;
            
            long long area = width*height;
            maxArea = max(maxArea,area);
            
        }
        
        return maxArea;
        
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends