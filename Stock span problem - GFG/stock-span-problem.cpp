//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    vector<int> getPrevGreater(int price[],int n){
        
        vector<int> ans;
        stack<int> st;
        
        for(int i = 0;i<n;i++){
            
            //remove all the smaller elements to the left
            while(!st.empty() && price[st.top()] <= price[i]){
                
                st.pop();
                
            }
            
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
                
            //push the index into stak
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       //keep previous gretare element
       vector<int> prevGreater = getPrevGreater(price,n);
       
       vector<int> ans;
       
       for(int i = 0;i<n;i++){
           
           ans.push_back(i - prevGreater[i]);
           
       }
       
       return ans;
       
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends