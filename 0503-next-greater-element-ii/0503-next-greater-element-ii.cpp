class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        nums.resize(2*n);
        
        //concatenating nums to the 2nd part to nums
        for(int i = n;i<2*n;i++){
            nums[i] = nums[i-n];
        }
        
        
        stack<int> st;
        vector<int> ans(n,-1);
        
        
        for(int i = 0;i<2*n;i++){
            
            while(!st.empty() && nums[i]>nums[st.top()]){
                
                if(st.top() >= n){
                    st.top() = st.top()-n;
                }
                
                ans[st.top()] = nums[i];
                st.pop();
                
            }
            st.push(i);
            
        }
        
        return ans;
        
        
    }
};