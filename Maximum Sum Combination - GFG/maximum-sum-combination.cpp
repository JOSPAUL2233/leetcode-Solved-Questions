//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        
        int n = A.size();
        int m = B.size();
        vector<int> ans;
        
        //sort both the arrays
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        //make a priority queue
        //which will store <sum,<Aindex,Bindex>>
        priority_queue<pair<int,pair<int,int>>> pq;
        
        //make a map or set to keep track of visited indices
        map<pair<int,int>,bool> visited;
        
        int sum = A[n-1] + B[m-1];
        
        //pusht the maximum sum value into pq and update visited
        pq.push({sum,{n-1,m-1}});
        visited[{n-1,m-1}] = true;
        
        //run the loop K times
        while(K--){
            
            //pop out the maximum sum and indices
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            ans.push_back(sum);
            
            //push (i-1,j) if they are not visited
            if( (i-1 >= 0) && (!visited[{i-1,j}] ) ){

                sum = A[i-1] + B[j];
                
                pq.push({sum,{i-1,j}});
                visited[{i-1,j}] = true;
                
            }
            
            //push (i,j-1) if they are not visited
            if( (j-1 >= 0) && (!visited[{i,j-1}]) ){
                
                sum = A[i] + B[j-1];
                
                pq.push({sum,{i,j-1}});
                visited[{i,j-1}] = true;
                
            }

        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends