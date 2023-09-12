class Solution {
public:
    
    vector<int> getPrevSmaller(vector<int> arr){
        
        vector<int> ans(arr.size(),-1);//store -1 by default
        stack<int> st;
        
        for(int i = 0;i<arr.size();i++){
            
            //remove all the greater elements
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    vector<int> getNextSmaller(vector<int> arr){
        
        vector<int> ans(arr.size(),arr.size());//store size by default
        stack<int> st;
        
        for(int i = arr.size()-1;i>=0;i--){
            
            //remove all the greater elements
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = arr.size();
            else
                ans[i] = st.top();
            
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> prevSmaller = getPrevSmaller(arr);
        vector<int> nextSmaller = getNextSmaller(arr);
        
        long sum = 0;
        int mod = pow(10,9) + 7;
        
        for(int i = 0;i<arr.size();i++){
            
            int left = i - prevSmaller[i];
            
            // cout<<"prev smaller:"<<prevSmaller[i]<<"  next smaller:"<<nextSmaller[i]<<endl;
            int right = nextSmaller[i] - i;
            
            // cout<<left<<" "<<right<<endl;
            
            sum += ((long)arr[i] * left * right);
            sum %= mod;
            
        }
        
        return sum;
        
    }
};