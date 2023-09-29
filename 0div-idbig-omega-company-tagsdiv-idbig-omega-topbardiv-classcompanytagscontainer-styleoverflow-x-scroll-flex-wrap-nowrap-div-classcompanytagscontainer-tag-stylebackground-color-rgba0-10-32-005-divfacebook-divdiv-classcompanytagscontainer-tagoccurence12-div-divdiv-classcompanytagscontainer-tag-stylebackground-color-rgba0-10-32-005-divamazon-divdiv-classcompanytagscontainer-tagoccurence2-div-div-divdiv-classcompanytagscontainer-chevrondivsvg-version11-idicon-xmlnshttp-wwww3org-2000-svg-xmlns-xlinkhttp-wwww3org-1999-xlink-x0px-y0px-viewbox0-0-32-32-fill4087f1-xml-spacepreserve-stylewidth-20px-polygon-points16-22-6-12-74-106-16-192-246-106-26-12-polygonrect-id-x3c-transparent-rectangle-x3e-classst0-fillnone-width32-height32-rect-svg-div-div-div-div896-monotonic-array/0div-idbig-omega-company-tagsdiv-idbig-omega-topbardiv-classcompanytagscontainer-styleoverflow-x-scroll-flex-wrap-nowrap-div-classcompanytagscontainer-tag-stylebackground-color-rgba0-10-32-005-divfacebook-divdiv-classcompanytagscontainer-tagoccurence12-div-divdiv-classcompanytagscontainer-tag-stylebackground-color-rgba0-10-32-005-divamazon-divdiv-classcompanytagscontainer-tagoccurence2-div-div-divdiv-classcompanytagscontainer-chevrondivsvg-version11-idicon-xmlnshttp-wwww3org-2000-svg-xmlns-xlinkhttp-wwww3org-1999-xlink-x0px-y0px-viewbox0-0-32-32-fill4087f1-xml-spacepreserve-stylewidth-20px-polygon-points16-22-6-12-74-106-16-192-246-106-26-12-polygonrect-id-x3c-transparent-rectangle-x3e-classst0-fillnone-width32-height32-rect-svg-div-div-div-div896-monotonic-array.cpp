class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool increasing = (nums[0] < nums[nums.size()-1]);
        
        for(int i = 0;i<nums.size()-1;i++){
            
            if(increasing){
                
                if(nums[i] > nums[i+1])
                    return false;
                
            }else{
                
                if(nums[i] < nums[i+1])
                    return false;
                
            }
            
        }
        
        return true;
        
    }
};