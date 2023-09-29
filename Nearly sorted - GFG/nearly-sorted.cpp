//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        
        //we will keep a window of size k+1 to put elements to priority queue
        //since the element can be found upto k steps forward(or backward)
        
        vector<int> ans(num,0);
        
        priority_queue<int,vector<int>,greater<int>> que;
        
        //put 1st k+1 elements into the priority queue
        for(int i = 0;i<=K;i++){
            
            que.push(arr[i]);
            
        }
        
        int index = 0;
        
        //now, iterate rest of the elements
        for(int i = K+1;i<num;i++){
            
            ans[index++] = que.top();
            que.pop();
            
            que.push(arr[i]);
            
        }
        
        //remove rest of the elements from the priority queue
        while(!que.empty()){
            
            ans[index++] = que.top();
            que.pop();
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends