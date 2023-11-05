//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string s,set<string> &ans,int index){
	        
	        if(index == s.size()){
	            
	            ans.insert(s);
	            return;
	            
	        }    
	        
	        for(int i = index;i<s.size();i++){
	            
	            swap(s[index],s[i]);
	            solve(s,ans,index+1);
	            swap(s[index],s[i]);
	            
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    
		    set<string> st;//to not to take duplicate permutations
		    int index = 0;
		    
		    solve(S,st,index);
		    
		    vector<string> ans;
		    
		    for(auto i : st){
		        
		        ans.push_back(i);
		        
		    }
		    
		    return ans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends