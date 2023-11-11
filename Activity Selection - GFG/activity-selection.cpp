//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        //make a vector or pairs
        vector<pair<int,int>> mp;
        
        for(int i = 0;i<start.size();i++){
            
            mp.push_back({end[i],start[i]});
            
        }
        
        //sort the vector
        sort(mp.begin(),mp.end());
        
        int lastEnd = 0;
        
        int work = 0;
        
        for(auto i : mp){
            
            if(i.second > lastEnd){
                
                work++;
                lastEnd = i.first;
                
            }
            
        }
        
        return work;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends