class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> greater(nums2.size(),-1);
        vector<int> ans(nums1.size());
        
        stack<int> st;
        
        for(int i = nums2.size()-1;i>=0;i--){
            
            
            while(!st.empty()){
                
                if(st.top()>nums2[i]){
                    
                    greater[i] = st.top();
    
                    break;    
                }
                
                st.pop();
            }
            
            st.push(nums2[i]);
            
        }
        
        
        for(int i = 0;i<nums1.size();i++){
            
            for(int j = 0;j<nums2.size();j++){
                
                if(nums1[i] == nums2[j])ans[i] = greater[j];
                
            }
            
        }
      
        return ans;
        
        
    }
};
