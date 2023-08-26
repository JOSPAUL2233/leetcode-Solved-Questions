//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(int num, string path){
        
        //base case
        if(path.size() == num){
            
            for(int i = 0;i<num-1;i++){
                
                if((path[i] == '1') && (path[i+1] == '1'))
                    return;
                
            }
            
            cout<<path<<" ";
            return;
            
        }
        
        path.push_back('0');
        solve(num,path);
        path.pop_back();
        
        path.push_back('1');
        solve(num,path);
        path.pop_back();
    
        
    }

    void generateBinaryStrings(int num){
        
        
        string path = "";
        
        solve(num,path);
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends