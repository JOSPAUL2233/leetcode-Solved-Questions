class Solution {
public:
    
    vector<int> getPrevGreater(vector<int> arr){
        
        vector<int> ans(arr.size(),-1);//store -1 by default
        stack<int> st;
        
        for(int i = 0;i<arr.size();i++){
            
            //remove all the smaller elements
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            
            //assign
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            //push current element into the stack
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    vector<int> getNextGreater(vector<int> arr){
        
        vector<int> ans(arr.size(),arr.size());//store size by default
        stack<int> st;
        
        for(int i = arr.size()-1;i>=0;i--){
            
            //remove all the smaller elements
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            
            //assign
            if(st.empty())
                ans[i] = arr.size();
            else
                ans[i] = st.top();
            
            //push current element into the stack
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    vector<int> getPrevSmaller(vector<int> arr){
        
        vector<int> ans(arr.size(),-1);//store -1 by default
        stack<int> st;
        
        for(int i = 0;i<arr.size();i++){
            
            //remove all the greater elements
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            //assign
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            //push current element into the stack
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
            
            //assign
            if(st.empty())
                ans[i] = arr.size();
            else
                ans[i] = st.top();
            
            //push current element into the stack
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    long long getLargestSum(vector<int> arr){
        
        vector<int> prevGreater = getPrevGreater(arr);
        vector<int> nextGreater = getNextGreater(arr);
        
        long long sum = 0;
        
        for(int i = 0;i<arr.size();i++){
            
            int left = i - prevGreater[i];
            int right = nextGreater[i] - i;
            
            sum += ((long long)arr[i] * left * right);
            
        }
        
        return sum;
        
    }
    
    long long getSmallestSum(vector<int> arr){
        
        vector<int> prevSmaller = getPrevSmaller(arr);
        vector<int> nextSmaller = getNextSmaller(arr);
        
        long long sum = 0;
        
        for(int i = 0;i<arr.size();i++){
            
            int left = i - prevSmaller[i];
            int right = nextSmaller[i] - i;
            
            sum += ((long long)arr[i] * left * right);
            
        }
        
        return sum;
        
    }
    
    long long subArrayRanges(vector<int>& nums) {
        
        long long ans = getLargestSum(nums) - getSmallestSum(nums);
        
        return ans;
        
    }
};