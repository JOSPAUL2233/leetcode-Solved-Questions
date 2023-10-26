//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int> piles,int h,int mid){
        
        int hours = 0;
        
        for(int i = 0;i<piles.size();i++){
            
            int timeToEat = piles[i]/mid;
            
            if(piles[i]%mid != 0){
                
                timeToEat++;
                
            }
            
            hours += timeToEat;
            
            //check if the hour limit crosses
            if(hours > h)
                return false;
            
        }
        
        return true;
        
    }
  
    int Solve(int N, vector<int>& piles, int H) {
        
        //range is from 1 till maxium bananas in a pile
        int start = 1;
        int end = 0;
        
        int ans = -1;
        
        for(int i : piles)
            if(i > end)
                end = i;
                
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(piles,H,mid)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends