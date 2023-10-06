//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //sort the meeting timings according to the ending time
        vector<pair<int,int>> meetings;
        for(int i = 0;i<n;i++){
            
            meetings.push_back({end[i],start[i]});
            
        }
        
        sort(meetings.begin(),meetings.end());
        
        //count the number of meetings that
        //can be help without overlapping
        
        int count = 1;
        int endingTime = meetings[0].first;
        
        for(int i = 1;i<n;i++){
            
            //if the new meeting can be held
            if(meetings[i].second > endingTime){
                
                count++;
                endingTime = meetings[i].first;//update current meeting
                
            }
            
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends