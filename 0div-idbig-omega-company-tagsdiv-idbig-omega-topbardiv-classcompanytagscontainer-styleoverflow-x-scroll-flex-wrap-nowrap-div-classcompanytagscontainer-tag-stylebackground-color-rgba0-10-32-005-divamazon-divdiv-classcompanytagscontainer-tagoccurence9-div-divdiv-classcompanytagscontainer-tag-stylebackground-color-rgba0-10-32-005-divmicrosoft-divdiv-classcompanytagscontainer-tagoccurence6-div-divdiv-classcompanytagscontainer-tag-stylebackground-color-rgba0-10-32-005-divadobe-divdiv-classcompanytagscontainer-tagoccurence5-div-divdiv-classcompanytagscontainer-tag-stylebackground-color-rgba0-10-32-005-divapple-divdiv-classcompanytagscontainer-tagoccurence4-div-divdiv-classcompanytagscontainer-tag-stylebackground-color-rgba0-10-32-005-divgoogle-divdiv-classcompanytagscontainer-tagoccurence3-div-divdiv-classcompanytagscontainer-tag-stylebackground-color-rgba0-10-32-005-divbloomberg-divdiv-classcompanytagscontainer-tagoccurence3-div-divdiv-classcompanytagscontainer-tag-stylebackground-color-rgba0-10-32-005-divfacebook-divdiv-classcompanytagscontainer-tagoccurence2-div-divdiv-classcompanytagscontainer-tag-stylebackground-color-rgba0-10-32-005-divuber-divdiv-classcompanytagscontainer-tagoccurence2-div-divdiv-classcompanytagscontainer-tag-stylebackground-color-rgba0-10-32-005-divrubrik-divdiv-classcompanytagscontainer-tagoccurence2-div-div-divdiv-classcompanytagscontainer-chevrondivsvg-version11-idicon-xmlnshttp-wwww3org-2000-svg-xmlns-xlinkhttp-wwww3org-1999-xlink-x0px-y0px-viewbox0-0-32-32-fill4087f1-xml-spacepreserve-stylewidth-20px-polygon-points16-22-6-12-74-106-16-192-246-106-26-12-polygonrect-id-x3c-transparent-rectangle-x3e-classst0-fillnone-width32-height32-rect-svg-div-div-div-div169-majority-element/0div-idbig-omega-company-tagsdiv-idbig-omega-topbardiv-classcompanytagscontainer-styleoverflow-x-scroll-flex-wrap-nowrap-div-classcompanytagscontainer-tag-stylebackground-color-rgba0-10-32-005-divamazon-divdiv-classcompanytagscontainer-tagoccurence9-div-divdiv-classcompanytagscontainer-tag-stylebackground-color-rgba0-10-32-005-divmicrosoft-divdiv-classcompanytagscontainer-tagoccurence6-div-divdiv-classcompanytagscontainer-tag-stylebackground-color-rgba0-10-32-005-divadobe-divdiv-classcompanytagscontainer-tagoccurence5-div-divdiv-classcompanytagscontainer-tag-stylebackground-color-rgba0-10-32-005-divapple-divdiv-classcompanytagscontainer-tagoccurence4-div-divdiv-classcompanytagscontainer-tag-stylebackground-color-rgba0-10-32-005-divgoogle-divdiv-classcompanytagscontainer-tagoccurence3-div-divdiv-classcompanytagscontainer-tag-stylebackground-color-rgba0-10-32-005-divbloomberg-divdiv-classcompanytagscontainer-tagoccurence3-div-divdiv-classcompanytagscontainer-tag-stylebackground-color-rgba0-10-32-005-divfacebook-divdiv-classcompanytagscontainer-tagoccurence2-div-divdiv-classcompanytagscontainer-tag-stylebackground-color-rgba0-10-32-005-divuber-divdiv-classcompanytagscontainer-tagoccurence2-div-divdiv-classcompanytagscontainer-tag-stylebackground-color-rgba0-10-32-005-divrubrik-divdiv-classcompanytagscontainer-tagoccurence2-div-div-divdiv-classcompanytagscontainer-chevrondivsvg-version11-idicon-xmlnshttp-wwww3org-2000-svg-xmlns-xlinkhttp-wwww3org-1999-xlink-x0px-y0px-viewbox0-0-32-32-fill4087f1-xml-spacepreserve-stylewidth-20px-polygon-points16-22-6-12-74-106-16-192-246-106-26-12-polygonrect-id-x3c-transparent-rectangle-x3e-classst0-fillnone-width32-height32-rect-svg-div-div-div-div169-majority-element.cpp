class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ele = 0;
        int count = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(count == 0){
                
                ele = nums[i];
                count = 1;
                
            }else if(ele == nums[i]){
                count++;
            }else{
                count--;
            }
            
        }
        
        //check if ele is the majority element
        
        count = 0;
        
        for(int i : nums)
            if(i == ele)
                count++;
        
        return count > nums.size()/2 ? ele : -1;
        
    }
};