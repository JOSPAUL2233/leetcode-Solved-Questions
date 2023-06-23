//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack<int> st;
        
        //push all the index into the stack
        for(int i = 0 ; i < n ; i++){
            
            st.push(i);
            
        }

        
        while(st.size() > 1){
            
            //pick up two elements
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            //check if a knows b and push if it can
            //be a candiate
            if(M[a][b] == 1){
                st.push(b);
            }else{
                st.push(a);
            }
            
        }
        
        //now, st.top() can be an answer if the array
        //contains any celebrity. so check for that
        //candidate
        
        int ans = st.top();
        
        //check for col
        int colOnes = 0;
        
        for(int i = 0;i<n;i++){
            
            if(M[i][ans] == 1)
                colOnes++;
                
        }
        
        if(colOnes != n-1)
            return -1;
            
        
        //check for raw
        int rawOnes = 0;
        
        for(int i = 0;i<n;i++){
            
            if(M[ans][i] == 1)
                rawOnes++;
            
        }
        
        if(rawOnes != 0)
            return -1;
        
        
        //if it overcame col and raw check, then it is the celebrity.
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends