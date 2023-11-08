//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        
        stack<int> st;
        
        for(int a : asteroids){
            
            if(a < 0){//to the left direction
                
                //keep right element in ele and make it +Ve to compare sizes
                int ele = abs(a);
                
                //iterate through out the stack
                while(!st.empty() && st.top() > 0 && ele != 0 ){
                    
                    if(st.top() == ele){//if both are equal
                        
                        st.pop();//distroy left
                        ele = 0;//and right element

                    }else if(st.top() < ele)
                        st.pop();//if left is smaller, distroy left element
                    else
                        ele = 0;//if right is smaller, distroy right element
                    
                }
                
                //if the right element was not distoyed
                if(ele != 0)
                    st.push(-ele);
                
            }else{//to the right direction
                
                st.push(a);
                
            }
            
        }
        
        //store the stack elements in a vector
        vector<int> ans(st.size(),0);
        
        for(int i = 0;i<ans.size();i++){
            ans[ans.size()-1-i] = st.top();
            st.pop();
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends