//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    void reverse(string &s,int left, int right){
        
        while(left < right){
            
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
    }
    
    string reverseWords(string s) 
    { 
        int left = 0;
        int right = 0;
        
        while(left < s.size()){
            
            //search for first non space character
            while(left < s.size() && s[left] == '.')
                left++;
                
            //if first position reaches at the end
            if(left == s.size())
                break;
                
            //
            right = left+1;
            
            while(right < s.size() && s[right] != '.')
                right++;
                
            reverse(s,left,right-1);
            
            left = right+1;
                
        }
        
        reverse(s,0,s.size()-1);
        
        return s;    
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends