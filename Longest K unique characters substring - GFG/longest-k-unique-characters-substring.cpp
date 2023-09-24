//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
    map<char,int> freq;
    
    int left = 0;
    int maxLength = 0;
    
    int distEle = 0;
    
    for(int right = 0;right<s.size();right++){
        
        freq[s[right]]++;
        
        //check if the element is already existing
        if(freq[s[right]] == 1)
            distEle++;
            
        while(left < right && distEle > k){
            
            freq[s[left]]--;
            
            if(freq[s[left]] == 0)
                distEle--;
            
            left++;
            
        }
        
        int length = right - left + 1;
        maxLength = max(length,maxLength);
        
    }
    
    return maxLength;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends