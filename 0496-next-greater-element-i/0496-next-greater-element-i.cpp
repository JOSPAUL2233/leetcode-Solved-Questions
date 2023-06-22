class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        vector<int> nextGreater(nums2.size(),0);
        
        for(int i=nums2.size()-1 ; i>=0 ; i--){
            
            //remove all the smaller elements to the right from stack
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            //update the answer
            if(st.empty()){
                nextGreater[i] = -1;
            }else{
                nextGreater[i] = st.top();
            }
            
            //push the current element into the stack
            st.push(nums2[i]);
            
        }
        
        //fetch the nextGreater elements which are needed (given in arr1)
        vector<int> fetched;
        
        for(int i = 0;i<nums1.size();i++){
            
            for(int j = 0;j<nums2.size();j++){
                
                if(nums1[i] == nums2[j]){
                    
                    fetched.push_back(nextGreater[j]);
                    
                }
                
            }
            
        }
        
        return fetched;
    }
};