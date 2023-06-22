//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 

        stack<int> st;
        vector<int> nextSmaller(n,0);
        
        for(int i=n-1 ; i>=0 ; i--){
            
            //remove all the greater elements to the right from stack
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            //update the answer
            if(st.empty()){
                nextSmaller[i] = -1;
            }else{
                nextSmaller[i] = st.top();
            }
            
            //push the current value into the stack
            st.push(arr[i]);
            
        }
        
        return nextSmaller;

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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends