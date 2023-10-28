//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        vector<int> first(26,0);
        vector<int> second(26,0);
        
        for(auto i : a){
            
            int num = i-'a';
            first[num]++;
            
        }
        
        for(auto i :b){
            
            int num = i-'a';
            second[num]++;
            
        }
        
        for(int i = 0;i<26;i++)
            if(first[i] != second[i])
                return false;
                
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends