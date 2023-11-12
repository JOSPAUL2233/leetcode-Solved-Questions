//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        
        long long first = -1;
        long long last = -1;
        
        long long start = 0;
        long long end = v.size()-1;
        
        //get the first occurance
        while(start <= end){
            
            long long mid = start + (end - start)/2;
            
            if(v[mid] == x){
                first = mid;
            }
            
            //shrink the search space
            if(v[mid] >= x)
                end = mid-1;
            else
                start = mid+1;
            
        }
        
        if(first == -1)
            return {-1,-1};
        
        start = 0;
        end = v.size()-1;
        //get the last occurance
        while(start <= end){
            
            long long mid = start + (end - start)/2;
            
            if(v[mid] == x){
                last = mid;
            }
            
            //shrink the search space
            if(v[mid] > x)
                end = mid-1;
            else
                start = mid+1;
            
        }        
        
        return {first,last};
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends