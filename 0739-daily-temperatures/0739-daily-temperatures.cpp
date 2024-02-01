class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        //apply next greater element approach
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        
        for(int i = temperatures.size()-1;i>=0;i--){
            
            //find the next greater element
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                
                st.pop();
                
            }
            
            if(!st.empty()){
                
                //store the difference
                ans[i] = st.top() - i;
                
            }
            
            st.push(i);
            
        }
        
        return ans;
        
    }
};