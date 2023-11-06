class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //edge case
        if(nums.size() <= 2)
            return nums.size();
        
        int index = 2;
        
        for(int i = 2;i<nums.size();i++){
            
            //checking two steps backward ones
            if(nums[index-2] != nums[i]){
                
                //store the value and move index forward
                nums[index] = nums[i];
                index++;
                
            }
            
        }
        
        return index;
        
    }
};