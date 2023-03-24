//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    
    void reverse(string &s){
        
        int n = s.size();
        
        for(int i = 0;i<n/2;i++){
            
            //swap
            char temp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = temp;
            
        }
        
    }
    
  public:
    string removeReverse(string S) {

        unordered_map<char,int> freq;
        
        //storing the frequency of each char
        for(int i = 0;i<S.size();i++){
            
            freq[S[i]]++;
            
        }
        
        int start = 0;
        int end = S.size()-1;
        
        bool front_dir = true;
        
        while(start<end){
            
            if(front_dir){
                // cout<<"freq(front):"<<freq[S[start]]<<endl;
                if(freq[S[start]] > 1){
                    
                    freq[S[start]]--;
                    S[start] = '#';
                    front_dir = !front_dir;
                    
                }
                
                start++;
                
            }else{
                // cout<<"freq(rev):"<<freq[S[end]]<<endl;
                if(freq[S[end]] > 1){
                    
                    freq[S[end]]--;
                    S[end] = '#';
                    front_dir = !front_dir;
                    
                }
                
                end--;
                
            }
           
        }
        
        // cout<<"outside:"<<S<<endl;
        
        string ans;
        
        for(int i = 0;i<S.size();i++){
            
            if(S[i]!='#')ans.push_back(S[i]);
            
        }
        
        if(front_dir)return ans;
        else{
            
            reverse(ans);
            return ans;
            
        }
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends