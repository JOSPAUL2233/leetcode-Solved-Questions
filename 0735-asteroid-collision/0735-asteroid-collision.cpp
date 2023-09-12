class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>s;
        for(auto a : asteroids){
            if(a > 0){
                s.push(a);
                continue;
            }
            int A = abs(a);
            while(!s.empty() && s.top()>0 && A > 0){
                if(s.top() == A){
                    s.pop();
                    A = 0;
                }
                else if(s.top() > A) A = 0;
                else{
                    s.pop();
                }
            }
            if(A > 0) s.push(-A);
        }

        vector<int>ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};