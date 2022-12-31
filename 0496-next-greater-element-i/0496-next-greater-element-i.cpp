class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        for(int i = 0;i<nums1.size();i++){
            
            int index = -1;
            int greater = -1;
            
            for(int j = 0;j<nums2.size();j++){
                
                if(nums1[i]==nums2[j])index = j;
                
                if((index != -1) && (nums2[j]>nums2[index])){
                    
                    greater = nums2[j];
                    break;
                    
                }
                
            }
            ans.push_back(greater);
            
            
        }
        
        
        return ans;
    }
};