class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> greatest(nums2.size(),-1);
        
        stack<int> s;
        s.push(0);
        
        for(int i = 1;i<nums2.size();i++){
            
            while((!s.empty()) && (nums2[s.top()] < nums2[i])){
                
                greatest[s.top()] = nums2[i];
                s.pop();
                
            }
            s.push(i);
            
        }
        
        vector<int> ans;
        
        for(int i = 0;i<nums1.size();i++){
            
            for(int j = 0;j<nums2.size();j++){
                
                if(nums1[i]==nums2[j])ans.push_back(greatest[j]);
                
            }
            
        }
        
        return ans;
        
    }
};