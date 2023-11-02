//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            
            int ptr1 = 0;
            int ptr2 = 0;
            int ptr3 = 0;
            
            vector<int> ans;
            
            while((ptr1 < n1) && (ptr2 < n2) && (ptr3 < n3)){
                
                if(A[ptr1] == B[ptr2] && A[ptr1] == C[ptr3]){
                    
                    
                    ans.push_back(A[ptr1]);
                    ptr1++;
                    ptr2++;
                    ptr3++;
                    
                    while(A[ptr1-1] == A[ptr1]) ptr1++;
                    while(B[ptr2-1] == B[ptr2]) ptr2++;
                    while(C[ptr3-1] == C[ptr3]) ptr3++;
                    
                    
                }else if(A[ptr1] <= B[ptr2] && A[ptr1] <= C[ptr3]){
                    
                    ptr1++;
                    
                }else if(B[ptr2] <= A[ptr1] && B[ptr2] <= C[ptr3]){
                    
                    ptr2++;
                    
                }else{
                    
                    ptr3++;
                    
                }
                
            }
            
            // vector<int> ans;
            
            // for(auto i : st){
            //     ans.push_back(i);
            // }
            
            return ans;
            
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends