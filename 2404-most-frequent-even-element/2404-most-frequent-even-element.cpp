class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        int count = 0;
        int element = -1;
        set<int> s;
        
        for(int i = 0;i<nums.size();i++){
            
            if(!(nums[i]&1) && !(s.count(nums[i]))){
                
                int sum = 0;
                for(int j = i;j<nums.size();j++){
                    
                    if(nums[i]==nums[j])sum++;
                    
                }
                
                if(sum>count){
                    count = sum;
                    element = nums[i];
                }
                if(sum==count){
                    count = sum;
                    element = element<nums[i]?element:nums[i];
                }
                
            }
            
        }
        
        return element;
        
    }
};