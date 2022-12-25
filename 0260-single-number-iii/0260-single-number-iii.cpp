class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> ans;
        
        int sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            sum^=nums[i];
            
        }
        
        int index = 0;
        
        for(int i = 0;i<31;i++){
            
            if(sum>>i & 1){
                index = i;
                break;
            }
            
        }
        
        int ones = 0;
        int zeroes = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i]>>index & 1){
                
                ones^=nums[i];
                
            }
            else{
                zeroes^=nums[i];
            }
            
        }
        
        ans.push_back(ones);
        ans.push_back(zeroes);
        
        return ans;
        
    }
};