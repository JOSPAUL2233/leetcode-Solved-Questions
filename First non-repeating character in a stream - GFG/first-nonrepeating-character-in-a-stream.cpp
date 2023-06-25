//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    queue<char> q;
		    string ans;
		   
		    //keep a track of count for each letters
		    map<char,int> count;

		    for(int i = 0;i<A.size();i++){

                //increate the count
    		    count[A[i]]++;
    		    
                //store the character in the queue
                q.push(A[i]);
            
                //check if 1st element is repeating or not
                
                while(!q.empty()){
                    
                    if(count[q.front()] > 1){
                    
                    q.pop();
                    
                    }else{
                        
                        ans.push_back(q.front());
                        break;
                        
                    }
                    
                }
                
		        //if the queue was empty
		        if(q.empty())
		            ans.push_back('#');
		        
		    }
		    
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends