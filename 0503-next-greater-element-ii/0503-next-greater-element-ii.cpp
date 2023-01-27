class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        vector<int> ans(nums.size(),0);
        
        for(int i = 0;i<nums.size();i++){
            
            int j = 0;
            
            if(i!=nums.size()-1)
             j = i+1;
            
            
                while(j!=i){
                                    
                    if(nums[j]>nums[i]){
                        
                        ans[i] = nums[j];
                        break;
                    }
                    
                    
                    if(j==nums.size()-1)j = 0;
                    else j++;
                    
                    
                    
                }
                if(j==i)ans[i] = -1;
            
        }
        
        return ans;
        
    }
};