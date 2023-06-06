//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	 
	    //make a vector of pairs -- (value,index)	    
	    vector<pair<int,int>> v;
	    
	    for(int i = 0;i<nums.size();i++){
	        
	        v.push_back({nums[i],i});
	        
	    }
	    
	    //sort the pairs vector
	    sort(v.begin(),v.end());
	    
	    //now, by iterating, count the number of swaps required
	    int swaps = 0;
	    
	    for(int i = 0;i<nums.size();i++){
	        
	        int value = v[i].first;
	        int index = v[i].second;
	        
	        if(i != index){
	            
	            swaps++;
	            swap(v[i],v[index]);
	            i--; //check in the same index again next time
	            
	        }
	        
	    }
	    
	    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends