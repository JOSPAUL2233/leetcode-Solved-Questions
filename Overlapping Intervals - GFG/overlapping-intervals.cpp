//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         
        sort(intervals.begin(),intervals.end());
         
        vector<vector<int>> ans;
         
        vector<int> p(2,0);
        p[0] = intervals[0][0];
        p[1] = intervals[0][1];
        
        for(int i = 1;i<intervals.size();i++){
            

            if(p[1] >= intervals[i][0]){//it is overlapping
                
                p[1] = max(p[1],intervals[i][1]);
                
            }else{//it is not overlapping
                
                //store the pairs and update it for the next iterations
                ans.push_back(p);
                p[0] = intervals[i][0];
                p[1] = intervals[i][1];
            }
        }
        
        ans.push_back(p);        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends