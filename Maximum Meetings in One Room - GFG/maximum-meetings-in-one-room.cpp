//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        //sort the meeting timings according to the ending time
        vector<pair<int,pair<int,int>>> meetings;
        
        for(int i = 0;i<N;i++){
            
            meetings.push_back({F[i],{S[i],i+1}});
            
        }
        
        sort(meetings.begin(),meetings.end());
        
        //count the number of meetings that
        //can be help without overlapping
        
        vector<int> ans;
        ans.push_back(meetings[0].second.second);//first meeting ongoing
        int endingTime = meetings[0].first;
        
        for(int i = 1;i<N;i++){
            
            //if the new meeting can be held
            if(meetings[i].second.first > endingTime){
                
                ans.push_back(meetings[i].second.second);
                endingTime = meetings[i].first;//update current meeting ending time
                
            }
            
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends