//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    
    
    //simple function to reverse the array
    void reverse(vector<int> &vec,int n){
        
        for(int i = 0;i<n/2;i++){
            
            swap(vec[i],vec[n-1-i]);
            
        }
        
    }
    
    vector<int> leaders(int a[], int n){
        
        vector<int> ans;
        
        //last element of an array is always greater.
        //(since there is no element to the left)
        ans.push_back(a[n-1]);
        
        //let the max from right side be the last element
        int max = a[n-1];
        
        //iterate from right to left and if there is a new max
        //then that is a leader and update the max accordingly
        
        for(int i = n-2 ; i >= 0 ; i--){

            //current element is also a leader
            if(max == a[i]){
                ans.push_back(max);
            }
            
            //new leader found
            if(a[i] > max){
                
                max = a[i];
                ans.push_back(max);
                
            }
            
        }
        
        //now, answer is in the reverse order(from right)
        //so reverse it and then return
        reverse(ans,ans.size());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends