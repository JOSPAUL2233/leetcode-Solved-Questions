//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        
        // steps to solve
        // 1. sort
        // 2. merget overlapping intervals
        // 3. search in each intervals
        
        //1. sort
        sort(range.begin(),range.end());
        
        //2. merge overlapping intervals
        vector<vector<int>> merged;
        
        vector<int> p;
        p.push_back(range[0][0]);
        p.push_back(range[0][1]);
        
        for(int i = 1;i<range.size();i++){
            
            if(range[i][0] <= p[1]){//overlapping
                
                p[1] = max(range[i][1] , p[1]);
                
            }else{
                
                merged.push_back(p);
                
                p[0] = range[i][0];
                p[1] = range[i][1];
                
            }
            
        }
        
        merged.push_back(p);
        
        //3. search in each intervals
        
        vector<int> ans;
        
        for(int i = 0;i<queries.size();i++){
            
            int position = queries[i];
            int currAns = -1;
            
            for(int j = 0;j<merged.size();j++){
                
                //find the total number of elements present
                int diff = merged[j][1] - merged[j][0] + 1;
                
                if(position <= diff){//position is in this interval
                    
                    currAns = merged[j][0] + position - 1;
                    break;
                    
                }else{
                    
                    position = position - diff;
                    
                }
                
            }
            
            ans.push_back(currAns);
            
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends