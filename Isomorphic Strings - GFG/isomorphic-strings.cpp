//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        //edge case
        if(str1.size() != str2.size())
            return false;
            
        unordered_map<char,char> left;
        unordered_map<char,char> right;
        
        for(int i = 0;i<str1.size();i++){
            
            //check if they are visited before
            char a = str1[i];
            char b = str2[i];
            
            //check for left side
            if(left.find(a) != left.end()){
                
                if(left[a] != b)
                    return false;
                
            }else{
                
                left[a] = b;
                
            }
            
            //check for right side
            if(right.find(b) != right.end()){
                
                if(right[b] != a)
                    return false;
                
            }else{
                
                right[b] = a;
                
            }
            
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends