class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>s;
        
        for(auto a : asteroids){
            
            //if the direction is right, push in stack and go for next asteroid
            if(a > 0){
                s.push(a);
                continue;
            }
            
            //if the direction is left
            
            int A = abs(a);
            
            //loop runs when there is a right element in stack
            //and left element is not yet destroyed
            while(!s.empty() && s.top()>0 && A > 0){
                
                if(s.top() == A){//if equal
                    
                    s.pop();//destroy left element
                    A = 0;//and right element
                }
                else if(s.top() > A)
                    A = 0;//if right is smaller, destroy the right element
                else{
                    s.pop();//if the left is greater, destroy the left element
                }
                
            }
            
            //if the right element is not distroyed, keep it
            if(A > 0) s.push(-A);
            
        }

        //keep the vector elements in a vector and return
        vector<int>ans;
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        //reverse the vector
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};