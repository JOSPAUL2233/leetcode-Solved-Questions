//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

        //copy the arr to do the sorting and manipulation
        vector<int> vec(arr.begin(),arr.end());
    
        //sort the array
        sort(vec.begin(),vec.end());
        
        //create a map to store the rank
        map<int,int> rank;
        
        //assign rank to each element in the array
        int ranking = 1;
        for(int i = 0;i<vec.size();i++){
            
            if(rank[vec[i]] == 0){
                
                rank[vec[i]] = ranking;
                ranking++;
                
            }
            
        }
        
        //copy the map values to the input array
        for(int i = 0;i<arr.size();i++){
            
            arr[i] = rank[arr[i]];
            
        }
        
        return arr;
        
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends